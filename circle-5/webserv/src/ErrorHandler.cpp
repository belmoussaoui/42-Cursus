#include "ErrorHandler.hpp"
#include "HttpHandler.hpp"
#include "Utils.hpp"

ErrorHandler::ErrorHandler(HttpResponse& response, std::stringstream& body_stream, const std::string &error_page) :
	_response(response), _body_stream(body_stream) , _error_map(), _error_page(error_page) {
}

ServerError::ServerError(HttpResponse& response, std::stringstream& body_stream, const std::string &error_page) : ErrorHandler(response, body_stream, error_page) {
	_error_map[500] = static_cast<void (ErrorHandler::*)()>(&ServerError::internalServerError);
	_error_map[501] = static_cast<void (ErrorHandler::*)()>(&ServerError::notImplemented);
	_error_map[504] = static_cast<void (ErrorHandler::*)()>(&ServerError::gatewayTimeout);
	_error_map[505] = static_cast<void (ErrorHandler::*)()>(&ServerError::HTTPVersion);
}

ClientError::ClientError(HttpResponse& response, std::stringstream& stream, const std::string &error_page) : ErrorHandler(response, stream, error_page) {
	_error_map[400] = static_cast<void (ErrorHandler::*)()>(&ClientError::badRequest);
	_error_map[403] = static_cast<void (ErrorHandler::*)()>(&ClientError::forbidden);
	_error_map[404] = static_cast<void (ErrorHandler::*)()>(&ClientError::notFound);
	_error_map[405] = static_cast<void (ErrorHandler::*)()>(&ClientError::methodNotAllowed);
	_error_map[408] = static_cast<void (ErrorHandler::*)()>(&ClientError::timeout);
	_error_map[413] = static_cast<void (ErrorHandler::*)()>(&ClientError::payloadTooLarge);
	_error_map[415] = static_cast<void (ErrorHandler::*)()>(&ClientError::unsupportedMediaType);
}

void ErrorHandler::errorProcess(int error) {
	if (!_error_page.empty() && Utils::pathToFileExist(_error_page)) {
		Utils::loadFile(_error_page, _body_stream);
	}
	else
		_error_page = "";
	if (_error_map.find(error) == _error_map.end())
		return ;
	else
		(this->*_error_map[error])();
	_response.map_headers["Content-Type"] = "text/html";
	_response.map_headers["Content-Length"] = Utils::intToString(_body_stream.str().length());
}

// ----------------------------- ClientError -----------------------------

ClientError::~ClientError() {}

void ClientError::badRequest() {
	_response.status_code = "400";
	_response.status_phrase = "Bad Request";
	if (_error_page.empty()) _body_stream << "<html><body><h1>400 Bad Request</h1></body></html>";
}

void ClientError::forbidden() {
	_response.status_code = "403";
	_response.status_phrase = "Forbidden";
	if (_error_page.empty()) _body_stream << "<html><body><h1>403 Forbidden</h1></body></html>";
}

void ClientError::notFound() {
	_response.status_code = "404";
	_response.status_phrase = "Not Found";
	if (_error_page.empty()) _body_stream << "<html><body><h1>404 Not Found</h1></body></html>";
}

void ClientError::methodNotAllowed() {
	_response.status_code = "405";
	_response.status_phrase = "Method Not Allowed";
	if (_error_page.empty()) _body_stream << "<html><body><h1>405 Method Not Allowed</h1></body></html>";
}

void ClientError::timeout() {
	_response.status_code = "408";
	_response.status_phrase = "Request Timeout";
	if (_error_page.empty()) _body_stream << "<html><body><h1>408 Request Timeout</h1></body></html>";
}

void ClientError::payloadTooLarge() {
	_response.status_code = "413";
	_response.status_phrase = "Payload Too Large";
	if (_error_page.empty()) _body_stream << "<html><body><h1>413 Payload Too Large</h1></body></html>";
}

void ClientError::unsupportedMediaType() {
	_response.status_code = "415";
	_response.status_phrase = "Unsupported Media Type";
	if (_error_page.empty()) _body_stream << "<html><body><h1>415 Unsupported Media Type</h1></body></html>";
}

// ----------------------------- ServerError -----------------------------

ServerError::~ServerError() {}

void ServerError::internalServerError() {
	_response.status_code = "500";
	_response.status_phrase = "Internal Server Error";
	if (_error_page.empty()) _body_stream << "<html><body><h1>500 Internal Server Error</h1></body></html>";
}

void ServerError::notImplemented() {
	_response.status_code = "501";
	_response.status_phrase = "Not Implemented";
	if (_error_page.empty()) _body_stream << "<html><body><h1>501 Not Implemented</h1></body></html>";
}

void ServerError::gatewayTimeout() {
	_response.status_code = "504";
	_response.status_phrase = "Gateway Timeout";
	if (_error_page.empty()) _body_stream << "<html><body><h1>504 Gateway Timeout</h1></body></html>";
}

void ServerError::HTTPVersion() {
	_response.status_code = "505";
	_response.status_phrase = "HTTP Version Not Supported";
	if (_error_page.empty()) _body_stream << "<html><body><h1>505 HTTP Version Not Supported</h1></body></html>";
}
