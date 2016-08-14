#include <iostream>

#include "Hello/ConsoleImpl.hh"

namespace hello {

ConsoleImpl::ConsoleImpl(int argc, const char **argv) : argc_(argc), argv_(argv) {}

std::string ConsoleImpl::sysArg() {
  if (argc_ < 2) {
    throw std::runtime_error("no argument");
  }
  return std::string(argv_[1]);
}
void ConsoleImpl::writeStdout(const char *msg) {
  std::cout << msg;
}

}
