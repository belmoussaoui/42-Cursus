#include "ServerConfig.hpp"

ServerConfig::ServerConfig(const JsonParser &parser)
{
	std::vector<json_value>::const_iterator it;
	std::vector<json_value> json_object_vector = parser.getJsonVector();
	for (it = json_object_vector.begin(); it != json_object_vector.end(); ++it)
	{
		server_config server = parseJsonObject(*it);
		_server_list.push_back(server);
	}
}

ServerConfig::~ServerConfig()
{
	std::cout << "Server config destructor called.\n";
}

std::list<server_config> ServerConfig::getServerList() const
{
	return _server_list;
}

server_config ServerConfig::parseJsonObject(const json_value &json_object)
{
	server_config server;
	server.max_body_size = 0;

	server.PORT = 8080;
	server.host = "0.0.0.0";
	server.name = "";
	std::map<std::string, routes> routes_map;
	std::map<std::string, json_value>::const_iterator it;
	std::map<std::string, json_value>::const_iterator sub_it;
	for (it = json_object.object_value.begin(); it != json_object.object_value.end(); it++)
	{
		std::string key = it->first;
		const json_value &value = it->second;
		if (key == "listen")
		{
			if (value.array_value.size() >= 1)
			{
				server.host = value.array_value[0].string_value;
			}
			if (value.array_value.size() >= 2)
			{
				server.PORT = value.array_value[1].number_value;
			}
		}
		else if (key == "name")
		{
			server.name = value.string_value;
		}
		else if (key == "max_body_size")
		{
			server.max_body_size = value.number_value;
			if (server.max_body_size == 0)
				server.max_body_size = 1;
		}
		else if (key == "error_pages")
		{
			for (sub_it = value.object_value.begin(); sub_it != value.object_value.end(); sub_it++)
			{
				std::string error_key = sub_it->first;
				const json_value &error_value = sub_it->second;
				server.error_pages[error_key] = error_value.string_value;
			}
		}
		else if (key == "routes")
		{
			for (sub_it = value.object_value.begin(); sub_it != value.object_value.end(); sub_it++)
			{
				std::string route_key = sub_it->first;
				const json_value &route_value = sub_it->second;
				routes route;
				route.handler = "";
				route.index = "";
				route.redir = "";
				route.methods[0] = "";
				route.methods[1] = "";
				route.methods[2] = "";
				route.root = "";
				route.autoindex = false;
				route.cgi = std::map<std::string, std::string>();
				std::map<std::string, json_value>::const_iterator sub_sub_it;
				for (sub_sub_it = route_value.object_value.begin(); sub_sub_it != route_value.object_value.end(); sub_sub_it++)
				{
					std::string route_info_key = sub_sub_it->first;
					const json_value &route_info_value = sub_sub_it->second;

					if (route_info_key == "root")
					{
						route.root = route_info_value.string_value;
					}
					else if (route_info_key == "methods")
					{
						for (size_t i = 0; i < route_info_value.array_value.size(); i++)
						{
							route.methods[i] = route_info_value.array_value[i].string_value;
						}
					}
					else if (route_info_key == "cgi")
					{
						for (std::map<std::string, json_value>::const_iterator sub_sub_sub_it = route_info_value.object_value.begin(); sub_sub_sub_it != route_info_value.object_value.end(); sub_sub_sub_it++)
						{
							std::string cgi_key = sub_sub_sub_it->first;
							const json_value &cgi_value = sub_sub_sub_it->second;
							route.cgi[cgi_key] = cgi_value.string_value;
						}
					}
					else if (route_info_key == "autoindex")
					{
						route.autoindex = route_info_value.boolean_value;
					}
					else if (route_info_key == "redir")
					{
						route.redir = route_info_value.string_value;
					}
					else if (route_info_key == "index")
					{
						route.index = route_info_value.string_value;
					}
					else if (route_info_key == "handler")
					{
						route.handler = route_info_value.string_value;
					}
				}
				routes_map[route_key] = route;
			}
			server.routes_map = routes_map;
		}
	}
	return server;
}

std::ostream &operator<<(std::ostream &os, const server_config &s)
{
	os << "host: " << s.host << std::endl;
	os << "port: " << s.PORT << std::endl;
	os << "name: " << s.name << std::endl;
	os << "max body size: " << s.max_body_size << std::endl;
	os << "error pages: " << std::endl;
	std::map<std::string, std::string>::const_iterator error_it;
	for (error_it = s.error_pages.begin(); error_it != s.error_pages.end(); ++error_it)
	{
		os << "    " << error_it->first << ": " << error_it->second << std::endl;
	}
	os << "routes: " << std::endl;
	std::map<std::string, routes>::const_iterator routes_it;
	std::map<std::string, std::string>::const_iterator cgi_it;
	for (routes_it = s.routes_map.begin(); routes_it != s.routes_map.end(); ++routes_it)
	{
		os << "    route: " << routes_it->first << std::endl;
		const routes &r = routes_it->second;
		os << "        root: " << r.root << std::endl;
		os << "        index: " << r.index << std::endl;
		os << "        handler: " << r.handler << std::endl;
		os << "        methods: ";
		for (int i = 0; i < 3; i++)
		{
			if (!r.methods[i].empty())
			{
				os << r.methods[i] << " ";
			}
		}
		os << std::endl;
		os << "        CGI: " << std::endl;
		for (cgi_it = r.cgi.begin(); cgi_it != r.cgi.end(); ++cgi_it)
		{
			os << "            " << cgi_it->first << ": " << cgi_it->second << std::endl;
		}
		os << "        auto index: " << std::boolalpha << r.autoindex << std::endl;
	}
	return os;
}
