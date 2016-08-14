#ifndef _HELLO_CLOCKIMPL_HH_
#define _HELLO_CLOCKIMPL_HH_

#include "Hello/Clock.hh"

namespace hello {

class ClockImpl : public Clock {
public:
  double getCurrentTime();
};

}

#endif
