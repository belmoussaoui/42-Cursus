const BASE_URL = 'https://127.0.0.1:8080';

const getToken = () => {
  return localStorage.getItem('token');
};

const getHeaders = (form) => {
  let headers = {}
  if (!form) {
    headers = {
      'Content-Type': 'application/json',
    };
  }
  const token = getToken();
  if (token) {
    headers.Authorization = `Token ${token}`;

  }
  return headers;
};

export const director = async (url, method = 'GET', data = null, form=false) => {
  const headers = getHeaders(form);
  const config = {
    method: method,
    headers: headers,
  };

  if (data) {
    config.body = form ? data : JSON.stringify(data);
  }

  const response = await fetch(`${BASE_URL}/${url}`, config);
  const responseData = await response.json();
  
  return responseData;

};