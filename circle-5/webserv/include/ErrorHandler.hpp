#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <sstream>
#include <map>

struct HttpResponse;

class ErrorHandler {

protected:
	HttpResponse&		_response;
	std::stringstream&	_body_stream;
	std::map<int, void(ErrorHandler::*)()> _error_map;
	std::string			_error_page;
public:
	ErrorHandler(HttpResponse& response, std::stringstream& body_stream, const std::string &error_page);
	ErrorHandler();
	void errorProcess(int error);
	virtual ~ErrorHandler() {};
};

class ClientError : public ErrorHandler {

public:
	ClientError(HttpResponse& response, std::stringstream& body_stream, const std::string &error_page);
	~ClientError();

	void badRequest(); 			// 400
	void forbidden(); 			// 403
	void notFound(); 			// 404
	void methodNotAllowed(); 	// 405
	void timeout(); 			// 408
	void payloadTooLarge(); 	// 413
	void unsupportedMediaType();// 415
};

class ServerError : public ErrorHandler {

public:
	ServerError(HttpResponse& request, std::stringstream& body_stream, const std::string &error_page);
	~ServerError();

	void internalServerError(); // 500
	void notImplemented(); 		// 501
	void gatewayTimeout(); 		// 504
	void HTTPVersion(); 		// 505
};

#endif
