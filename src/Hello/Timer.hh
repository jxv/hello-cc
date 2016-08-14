#ifndef _HELLO_TIMER_HH_
#define _HELLO_TIMER_HH_

#include <functional>

namespace hello {

class Timer {
public:
  virtual void measure(std::function<void()>) = 0;
};

}

#endif
