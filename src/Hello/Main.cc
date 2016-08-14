#include <iostream>

#include "Hello/Main.hh"

namespace hello {

int main(Timer &timer, Greeter &greeter, Configuration &configuration) {
  try {
    auto target = configuration.getTarget();
    timer.measure([&greeter, &target] {
      greeter.greet(target);
    });
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}

}
