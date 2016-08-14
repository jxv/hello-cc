#include "Hello/GreeterImpl.hh"

namespace hello {

GreeterImpl::GreeterImpl(Console &console) : console_(console) {}

void GreeterImpl::greet(std::string &msg) {
  console_.writeStdout("Hello, ");
  console_.writeStdout(msg.c_str());
  console_.writeStdout("!\n");
}

}
