#include "App.hpp"
#include "esp_log.h"

static const char* TAG = "App";

App::App() : nvs() {}

void App::init() {
  ESP_LOGI(TAG, "Initializing application...");
  nvs.init();
}

void App::run() {
  xTaskCreate(&App::mainTask, "mainTask", 4096, this, 5, nullptr);
}

void App::mainTask(void* pvParameter) {
  App* app = static_cast<App*>(pvParameter);
  ESP_LOGI(TAG, "Running main task...");

  while (true) {
    // Main application loop
    printf("Hello world!\r\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
