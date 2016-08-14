#include <exception>

#include "Hello/ConfigurationImpl.hh"

namespace hello {

ConfigurationImpl::ConfigurationImpl(Console &console, FileSystem &fileSystem)
: console_(console)
, fileSystem_(fileSystem)
{}

std::string ConfigurationImpl::getTarget() {
  auto filePath = console_.sysArg();
  auto target = fileSystem_.readFile(filePath);
  return target;
}

}
