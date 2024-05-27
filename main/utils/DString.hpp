#ifndef DSTRING_HPP
#define DSTRING_HPP

#define DSTRING_CONFIG_USE_SPRINTF (0)

#include <string.h>

#if (DSTRING_CONFIG_USE_SPRINTF == 1)
#include <stdarg.h>
#include <stdio.h>
#endif // (DSTRING_CONFIG_USE_SPRINTF == 1)

class DString {
  char* buff_p = NULL;

  int len   = 0;
  int size  = 0;

  bool overflow = false;

  public:
    DString(size_t size);
    ~DString();

    bool add(const char* str_p);

#if (DSTRING_CONFIG_USE_SPRINTF == 1)
    bool sprintf(const char* format, ...);
#endif // (DSTRING_CONFIG_USE_SPRINTF == 1)

    const char* c_str() const;
    size_t length() const;
};

#endif // DSTRING_HPP
