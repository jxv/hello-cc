#ifndef _HELLO_CONSOLEIMPL_HH_
#define _HELLO_CONSOLEIMPL_HH_

#include "Hello/Console.hh"

namespace hello {

class ConsoleImpl : public Console {
public:
  std::vector<std::string> sysArgs();
  void writeStdout(const char *msg);
};

}

#endif
