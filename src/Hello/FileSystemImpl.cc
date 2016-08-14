#include <iostream>
#include <fstream>

#include "Hello/FileSystemImpl.hh"

namespace hello {

std::string FileSystemImpl::readFile(std::string &path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("no file: " + path);
  }
  char line[256];
  file.getline(line, 256);
  return std::string(line);
}

}
