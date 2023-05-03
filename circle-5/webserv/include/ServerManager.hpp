#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include "HttpHandler.hpp"
#include "ServerConfig.hpp"

#include <iostream>
#include <errno.h>
#include <map>
#include <utility>		 // pair
#include <string>
#include <cstring> 		 // memset
#include <stdio.h>		 // perror
#include <sys/socket.h>	 // socket, bind, accept...
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <poll.h>
#include <arpa/inet.h>	 // inet_ntoa
#include <cassert>
#include <fcntl.h>		 // fcntl
#include <netinet/tcp.h> // TCP_NODELAY
#include <csignal>
#include <stack>

#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLACK	"\033[1;30m"

#if (defined (LINUX) || defined (__linux__))
#include <sys/epoll.h>  // epoll
#else
#include <sys/event.h>  // kqueue
#endif

# define BUFFER_SIZE 4096
# define MAX_EVENTS 4096
# define TIMEOUT_SECS 5
# define WAIT_TIMEOUT_SECS 2

struct server : public server_config {
	int	listen_fd;

    server(const server_config& info) : server_config(info) {};
};

typedef std::map<int, HttpHandler*> map_type;
typedef std::map<int, HttpHandler*>::iterator 			map_iterator_type;

typedef std::map<std::string, server>					server_name_level3;
typedef std::map<std::string, server_name_level3>		host_level2;
typedef std::map<int, host_level2>						fd_port_level1;

class ServerManager {

private:
	fd_port_level1		_list_server_map;
	map_type			_client_map;

#if (defined (LINUX) || defined (__linux__))
	int		_epoll_fd;
#else
	int		_kqueue_fd;
#endif

#include "macros.hpp"

typedef std::pair<int, HttpHandler*> fd_client_pair;

public:
    ServerManager(const ServerConfig &config);
    ~ServerManager();

    void	run();
	void	setNonBlockingMode(int socket);
	void	setupSocket(server &serv);

	const int* hostLevel(int fd) ;

	void	epollInit();
	host_level2*	isPartOfListenFd(int fd) ;

	int 	treatReceiveData(char *buffer, const ssize_t nbytes, HttpHandler *client);
	int		readFromClient(fd_client_pair client);
	void	writeToClient(int client_fd, const std::string &str);

	void	handleReadEvent(fd_client_pair client);
	void	handleWriteEvent(fd_client_pair client);
	void 	handleNewConnection(int socket, host_level2* server_map);

	void	eventManager();
	void	timeoutCheck();
	void	connectionCloseMode(fd_client_pair client);
    void	closeClientConnection(fd_client_pair client);
	void	closeClientConnection(fd_client_pair client, map_iterator_type elem);

};

#endif
