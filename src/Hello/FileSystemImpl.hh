#ifndef _HELLO_FILESYSTEMIMPL_HH_
#define _HELLO_FILESYSTEMIMPL_HH_

#include "Hello/FileSystem.hh"

namespace hello {

class FileSystemImpl : public FileSystem {
public:
  std::string readFile(std::string &path);
};

}

#endif
