#include <sstream>

#include "Hello/NotifierImpl.hh"

namespace hello {

NotifierImpl::NotifierImpl(Console &console) : console_(console) {}

void NotifierImpl::timeTaken(double seconds) {
  console_.writeStdout("time: ");
  {
    std::ostringstream stream;
    stream << seconds;
    std::string string = stream.str();
    console_.writeStdout(string.c_str());
  }
  console_.writeStdout("s\n");
}

}
