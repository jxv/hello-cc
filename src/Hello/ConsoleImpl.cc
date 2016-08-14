#include <iostream>

#include "Hello/ConsoleImpl.hh"

namespace hello {

std::vector<std::string> ConsoleImpl::sysArgs() {
  return {};
}
void ConsoleImpl::writeStdout(const char *msg) {
  std::cout << msg;
}

}
