import requests
import socket
import os

# get the directory of the current Python script
script_dir = os.path.dirname(os.path.abspath(__file__))
script_dir = script_dir + "/"

URL = 'http://localhost:8080/'

# Send a GET request
def test_get():
	response = requests.get(URL)
	assert(response.status_code == 200)
	assert(response.headers['content-type'] == 'text/html')
	response = requests.get(URL + '/random')
	assert(response.status_code == 404)

# Send a POST request with data
def test_post():
	data = {'username': 'john', 'password': 'doe'}
	response = requests.post(URL + 'login', data=data)
	assert(response.status_code == 200)
	assert(response.text == "Response to application/x-www-form-urlencoded")
	# large file
	files = {'file': open(script_dir + 'files/large_file.txt', 'rb')}
	response = requests.post(URL + 'form/upload', files=files)
	assert(response.status_code == 413)

# Send a DELETE request
def test_delete():
	response = requests.delete(URL + 'upload/123')
	assert(response.status_code == 404)
	response = requests.delete(URL + '/cgi/add.py')
	assert(response.status_code == 405)

# Upload file -> GET file -> DELETE file
def test_upload_file():
	files = {'file': open(script_dir + 'files/upload.txt', 'rb')}
	response = requests.post(URL + 'form/upload', files=files)
	assert(response.status_code == 201)
	response = requests.get(URL + 'upload/upload.txt')
	assert(response.status_code == 200)
	response = requests.delete(URL + 'upload/upload.txt')
	assert(response.status_code == 204)

# Testing redirection in a socket
def test_redir():
	ADDRESS = "0.0.0.0"
	PORT = 8080
	REQUEST = """\
	GET /redir HTTP/1.1\r
	Host: 0.0.0.0\r
	\r
	"""
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((ADDRESS, PORT))
	s.send(REQUEST.encode())
	data = s.recv(1024)
	assert data.decode().startswith("HTTP/1.1 301")
	s.close()

def chunker(data, size):
	for i in range(0, len(data), size):
		chunk = data[i:i+size]
		yield chunk.encode()

def test_chunked():
	headers = {
		"Transfer-Encoding": "chunked",
		"Content-Type": "text/plain",
	}
	data = "This is the data to be sent in chunks"
	response = requests.post(URL + 'sendback', headers=headers, data=chunker(data, 5))
	assert response.text == data
	assert response.status_code == 200

# Testing cgi with addition and substraction
def test_cgi():
	num1 = 5
	num2 = 6
	url = "form/add/add.py?num1={0}&num2={1}".format(num1, num2)
	calc = "{0} + {1} = {2}".format(num1, num2, num1 + num2)
	response = requests.get(URL + url)
	assert(response.status_code == 200)
	assert(response.text.startswith("<h1>Addition Results</h1>\n<output>" + calc))

	num3 = 8
	num4 = 9
	url = "form/sub/sub.php?num1={0}&num2={1}".format(num3, num4)
	calc = "{0} - {1} = {2}".format(num3, num4, num3 - num4)
	response = requests.get(URL + url)
	assert(response.status_code == 200)
	assert(response.text.startswith("<h1>Substraction Results</h1><output>" + calc))

