// main.cpp
// #include "App.hpp"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_log.h"

#include <stdio.h>

#include "DString.hpp"

extern "C" void app_main() {
  DString str(8);

  str.add("Hello");
  str.add(" world");
  str.add("!");

  // bool res = str.sprintf("%d", 12);

  // printf("Res = %s\n", res?"OK":"Overflow");

  printf("%s\n", str.c_str());

  // App app;
  // app.init();
  // app.run();

  // // Prevent app_main from returning
  // vTaskDelete(NULL);
}
