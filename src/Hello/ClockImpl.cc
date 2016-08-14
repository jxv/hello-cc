#include <ctime>

#include "Hello/ClockImpl.hh"

namespace hello {

double ClockImpl::getCurrentTime() {
  std::clock_t clock = std::clock();
  return clock / (double) CLOCKS_PER_SEC;
}

}
