#include "DString.hpp"

DString::DString(size_t size) {
  buff_p = new char[size];
  memset(buff_p, 0, size);
  this->size = size;
}

DString::~DString() {
  delete[] buff_p;
}

#include <stdio.h>

bool DString::add(const char* str_p) {
  int remain = (size - len) - 1;
  if (remain > 0) {
    strncat(buff_p, str_p, remain);
    len += strlen(str_p);
  }
  remain = (size - len) - 1;
  return remain > 0;
}

#if (DSTRING_CONFIG_USE_SPRINTF == 1)
bool DString::sprintf(const char* format, ...) {
  int ret = 0;
  va_list params;

  int remain = this->size - this->len;

  if (!overflow) {
    va_start(params, format);
    ret = vsnprintf(buff_p + this->len, remain, format, params);
    va_end(params);

    if (ret < remain) {
      this->len += ret;
    } else {
      overflow = true;
    }
  }

  return !overflow;
}
#endif // (DSTRING_CONFIG_USE_SPRINTF == 1)

const char* DString::c_str() const {
  return buff_p;
}

size_t DString::length() const{
  return len;
}
