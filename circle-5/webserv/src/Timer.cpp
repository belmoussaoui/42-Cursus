#include "Timer.hpp"

Timer::Timer(int timeout_seconds) : _timeout_seconds(timeout_seconds), _running(false){

}

Timer::~Timer() {

}

void Timer::start() {
	gettimeofday(&_last_read, NULL);
	_running = true;
}

void Timer::stop() {
	_running = false;
}

bool Timer::hasTimeOut() {
	if (_running) {
		struct timeval now;
		gettimeofday(&now, NULL);
		double elapsed_seconds = (now.tv_sec - _last_read.tv_sec) + (now.tv_usec - _last_read.tv_usec) / 1000000.0;
		if (elapsed_seconds > _timeout_seconds) {
			_running = false;
			return true;
		}
	}
	return false;
}
