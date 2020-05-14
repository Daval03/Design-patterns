#ifndef DATOS_2___2_0_CALLBACKTIMER_H
#define DATOS_2___2_0_CALLBACKTIMER_H

#include <functional>
#include <chrono>
#include <future>
#include <cstdio>

class CallBackTimer
{
public:
    CallBackTimer()
            :_execute(false)
    {}

    void start(int interval, const std::function<void(void)>& func)
    {
        _execute = true;
        std::thread([=]()
                    {
                        while (_execute) {
                            func();
                            std::this_thread::sleep_for(
                                    std::chrono::milliseconds(interval));
                        }
                    }).detach();
    }

    void stop()
    {
        _execute = false;
    }

private:
    bool _execute;

};


#endif //DATOS_2___2_0_CALLBACKTIMER_H
