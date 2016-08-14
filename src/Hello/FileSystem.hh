#ifndef HELLO_FILESYSTEM_HH
#define HELLO_FILESYSTEM_HH

#include <string>

namespace hello {

class FileSystem {
public:
  virtual std::string readFile(std::string &path) = 0;
};

}

#endif
