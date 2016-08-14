#ifndef _HELLO_GREETER_HH_
#define _HELLO_GREETER_HH_

#include <string>

namespace hello {

class Greeter {
public:
  virtual void greet(std::string &msg) = 0;
};

}

#endif
