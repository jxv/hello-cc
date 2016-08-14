#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "Hello/FileSystem.hh"
#include "Hello/ConsoleImpl.hh"
#include "Hello/ClockImpl.hh"
#include "Hello/Configuration.hh"
#include "Hello/GreeterImpl.hh"
#include "Hello/TimerImpl.hh"

int main() {
  // Wiring
  auto console = hello::ConsoleImpl();
  auto clock = hello::ClockImpl();
  auto greeter = hello::GreeterImpl(console);
  auto timer = hello::TimerImpl(console, clock);

  try {
    timer.measure([&greeter] {
      auto world = std::string("world");
      greeter.greet(world);
    });
  }
  catch (std::exception &e) {
    std::cout << e.what();
  }
  return 0;
}
