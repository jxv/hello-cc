#include "Hello/TimerImpl.hh"

namespace hello {

TimerImpl::TimerImpl(Console &console, Clock &clock) : console_(console), clock_(clock) {}

void TimerImpl::measure(std::function<void()> f) {
  auto start = clock_.getCurrentTime();
  f();
  auto end = clock_.getCurrentTime();
  console_.writeStdout("time: ");
  auto diff = end - start;
  console_.writeStdout("\n");
}

}
