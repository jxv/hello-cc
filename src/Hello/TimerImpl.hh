#ifndef _HELLO_TIMERIMPL_HH_
#define _HELLO_TIMERIMPL_HH_

#include "Hello/Notifier.hh"
#include "Hello/Clock.hh"
#include "Hello/Timer.hh"

namespace hello {

class TimerImpl : public Timer {
public:
  TimerImpl(Notifier &notifier, Clock &clock);
  void measure(std::function<void()> f);
private:
  Notifier &notifier_;
  Clock &clock_;
};

}

#endif
