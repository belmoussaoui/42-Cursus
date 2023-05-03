#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include "JsonParser.hpp"

#include <list>

struct routes {
	std::string root;
	std::string redir;
	std::string methods[3];
	std::string index;
	std::string handler;
	std::map<std::string, std::string> cgi;
	bool		autoindex;
};

struct server_config {
	std::string host;
	std::string name;
	int			PORT;
	int			max_body_size;
	std::map<std::string, std::string> error_pages;
	std::map<std::string, routes> routes_map;
	bool		is_default;
};

class ServerConfig {

private:
	std::list<server_config>	_server_list;

public:
    ServerConfig(const JsonParser &parser);
	server_config parseJsonObject(const json_value &json_object);

	std::list<server_config> getServerList() const;
    ~ServerConfig();
};

std::ostream& operator<<(std::ostream& os, const server_config& s);

#endif
