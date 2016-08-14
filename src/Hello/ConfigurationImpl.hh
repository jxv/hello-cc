#ifndef _HELLO_CONFIGURATIONIMPL_HH_
#define _HELLO_CONFIGURATIONIMPL_HH_

#include "Hello/Configuration.hh"
#include "Hello/Console.hh"
#include "Hello/FileSystem.hh"

namespace hello {

class ConfigurationImpl : public Configuration {
public:
  ConfigurationImpl(Console &console, FileSystem &fileSystem);
  std::string getTarget();
private:
  Console &console_;
  FileSystem &fileSystem_;
};

}

#endif
