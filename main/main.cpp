// main.cpp
#include "App.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern "C" void app_main() {
  App app;
  app.init();
  app.run();

  // Prevent app_main from returning
  vTaskDelete(NULL);
}
