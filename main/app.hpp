#ifndef APP_HPP
#define APP_HPP

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "NVS.hpp"

class App {
public:
    App();
    void init();
    void run();

private:
    NVS nvs;
    static void mainTask(void* pvParameter);
};

#endif // APP_HPP
