#ifndef DEF_CALLBACKTIMER
#define DEF_CALLBACKTIMER

#include <functional>
#include <chrono>
#include <future>
#include <cstdio>
#include "Scene.h"

class CallBackTimer
{
public:
	CallBackTimer();
	~CallBackTimer();
	void stop();
	void start(int interval, std::function<void(Scene*,bool)> func);
	bool is_running() const noexcept;
private:
	std::atomic<bool> _execute;
	std::thread _thd;
};

#endif
