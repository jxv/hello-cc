#ifndef _HELLO_CONSOLEIMPL_HH_
#define _HELLO_CONSOLEIMPL_HH_

#include "Hello/Console.hh"

namespace hello {

class ConsoleImpl : public Console {
public:
  ConsoleImpl(int argc, const char **argv);
  std::string sysArg();
  void writeStdout(const char *msg);
private:
  int argc_;
  const char **argv_;
};

}

#endif
