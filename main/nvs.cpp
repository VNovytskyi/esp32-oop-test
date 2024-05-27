#include "NVS.hpp"
#include "esp_log.h"

static const char* TAG = "NVS";

NVS::NVS() : handle(0) {}

esp_err_t NVS::init() {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    if (err == ESP_OK) {
        err = nvs_open("storage", NVS_READWRITE, &handle);
    }
    return err;
}

esp_err_t NVS::readString(const char* key, std::string& out_value) {
    size_t required_size;
    esp_err_t err = nvs_get_str(handle, key, nullptr, &required_size);
    if (err == ESP_OK) {
        char* value = new char[required_size];
        err = nvs_get_str(handle, key, value, &required_size);
        if (err == ESP_OK) {
            out_value = std::string(value);
        }
        delete[] value;
    }
    return err;
}

esp_err_t NVS::writeString(const char* key, const std::string& value) {
    return nvs_set_str(handle, key, value.c_str());
}
