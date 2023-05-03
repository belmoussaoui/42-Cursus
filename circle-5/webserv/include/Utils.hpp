#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <sys/stat.h> // stat()
#include <dirent.h> //closedir()
#include <iostream>
#include <unistd.h>
#include <iomanip> // setfill()
#include <dirent.h>	// opendir()

namespace Utils {

	bool 			pathToFileExist(const std::string& path);
	bool 			isDirectory(const std::string& path);
	bool			correctPath(const std::string& path);
	std::string		intToString(int value);

	std::string 	urlDecode(const std::string &url);
	void			loadFile(const std::string &fileName, std::stringstream &stream) ;

	std::ofstream*	createOrEraseFile(std::string fileName);
	int				directoryListing(const std::string &dir);
	bool			hasExecutePermissions(const char* filepath);
}

#endif
