#ifndef HTTPHANDLER_HPP
#define HTTPHANDLER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "Utils.hpp"
#include "ServerConfig.hpp"
#include "ErrorHandler.hpp"
#include "Timer.hpp"
#include "CGIExecutor.hpp"

# define EOF_CHUNKED "\r\n0\r\n\r\n"
# define CRLF "\r\n\r\n"
# define ROOT_PATH "www"

struct server;

typedef std::map<std::string, server>		server_name_level3;

struct HttpMessage {
    std::string method;
    std::string url;
    std::string version;
	std::string host;
    std::map<std::string, std::string> map_headers;
    bool has_body;
    size_t body_length;
};

struct HttpResponse {
    std::string version;
    std::string status_code;
    std::string status_phrase;
    std::map<std::string, std::string> map_headers;
};


class HttpHandler {

private:
	Timer				_timer;
	std::stringstream	_readStream;
	std::stringstream   _request_body_stream;
	std::stringstream   _response_header_stream;
	std::stringstream   _response_body_stream;
	HttpMessage			_request;
	HttpResponse		_response;
	char				_last_4_char[4];
	ssize_t				_left_to_read;
	std::map<std::string, std::string> _MIME_TYPES;
	server_name_level3*	_serv_map;
	server_config*		_server;

	bool				_close_keep_alive;
	bool				_body_size_exceeded;
	bool				_ready_to_write;
	bool				_transfer_chunked;

	routes				_default_route;
	routes*				_active_route;

public:
	HttpHandler(int timeout_seconds, server_name_level3 *serv_map);
	~HttpHandler();

	bool	isKeepAlive() const;
	bool	isReadyToWrite() const;
	bool	invalidRequest() const;
	bool	isBodyUnfinished() const ;
	bool	isAllowedMethod(const std::string &method) const;
	bool	findHeader(const std::string &header, std::string &value) const;

	HttpMessage		getStructRequest() const;
	std::string		getRequest() const;
	std::string		getBody() const;
	ssize_t			getLeftToRead() const;
	std::string		getResponseHeader() const;
	std::string		getResponseBody() const;
	std::string		getContentType(const std::string& path) const;

	void	assignServerConfig();
	void	setReadyToWrite(bool ready);
	void	writeToStream(char *buffer, ssize_t nbytes) ;
	int		writeToBody(char *buffer, ssize_t nbytes);

	void	copyLast4Char(char *buffer, ssize_t nbytes);
	void	resetRequestContext();
	void 	resetLast4();
	void	startTimer();
	void	stopTimer();
	bool	hasTimeOut();

	void	unchunckMessage();
	void	handleCGI(const std::string &original_url);
	void	error(int error) ;
	void 	redirection();
	void	uploadFile(const std::string& contentType, size_t pos_boundary);
	void	setupRoute(const std::string &url);
	void	generate_directory_listing_html(const std::string& directory_path);

	void	parseRequest();
	void	createHttpResponse();
	void	constructStringResponse();

	void	GET();
	void	POST();
	void	DELETE();
};

#endif
