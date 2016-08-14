#ifndef _HELLO_GREETERIMPL_HH_
#define _HELLO_GREETERIMPL_HH_

#include "Hello/Greeter.hh"
#include "Hello/Console.hh"

namespace hello {

class GreeterImpl : public Greeter {
public:
  GreeterImpl(Console &console);
  void greet(std::string &msg);
private:
  Console &console_;
};

}

#endif
