#include "Hello/TimerImpl.hh"

namespace hello {

TimerImpl::TimerImpl(Notifier &notifier, Clock &clock) : notifier_(notifier), clock_(clock) {}

void TimerImpl::measure(std::function<void()> f) {
  auto start = clock_.getCurrentTime();
  f();
  auto end = clock_.getCurrentTime();
  auto duration = end - start;
  notifier_.timeTaken(duration);
}

}
