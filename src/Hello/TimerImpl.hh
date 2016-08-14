#ifndef _HELLO_TIMERIMPL_HH_
#define _HELLO_TIMERIMPL_HH_

#include "Hello/Console.hh"
#include "Hello/Clock.hh"
#include "Hello/Timer.hh"

namespace hello {

class TimerImpl : public Timer {
public:
  TimerImpl(Console &console, Clock &clock);
  void measure(std::function<void()> f);
private:
  Console &console_;
  Clock &clock_;
};

}

#endif
