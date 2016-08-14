#ifndef _HELLO_CONFIGURATION_HH_
#define _HELLO_CONFIGURATION_HH_

#include <string>

namespace hello {

class Configuration {
public:
  virtual std::string target() = 0;
};

}

#endif
