#ifndef NVS_HPP
#define NVS_HPP

#include "nvs_flash.h"
#include <string>

class NVS {
public:
    NVS();
    esp_err_t init();
    esp_err_t readString(const char* key, std::string& out_value);
    esp_err_t writeString(const char* key, const std::string& value);

private:
    nvs_handle_t handle;
};

#endif // NVS_HPP
