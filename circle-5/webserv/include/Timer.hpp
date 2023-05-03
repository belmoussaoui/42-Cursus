#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <sys/time.h>

class Timer {

private:
	int 			_timeout_seconds;
	struct timeval	_last_read;
	bool			_running;

public:
    Timer(int _timeout_seconds);
	void start();
	void stop();
	bool hasTimeOut();
    ~Timer();
};

#endif
