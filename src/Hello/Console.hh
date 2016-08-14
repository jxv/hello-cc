#ifndef _HELLO_CONSOLE_HH_
#define _HELLO_CONSOLE_HH_

#include <string>
#include <vector>

namespace hello {

class Console {
public:
  virtual std::vector<std::string> sysArgs() = 0;
  virtual void writeStdout(const char *) = 0;
};

}

#endif
