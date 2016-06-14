#include <iostream>
#include <string>
#include <vector>
#include <functional>

class FileSystem {
public:
  virtual std::string readFile(std::string &path) = 0;
};

class Console {
public:
  virtual std::vector<std::string> sysArgs() = 0;
  virtual void writeStdout(const char *) = 0;
};

class Clock {
public:
  virtual double getCurrentTime() = 0;
};

class Configuration {
public:
  virtual std::string target() = 0;
};

class Exit {
public:
  virtual void errorExit(std::string &msg) = 0;
};

class Greeter {
public:
  virtual void greet(std::string &msg) = 0;
};

class Timer {
public:
  virtual void measure(std::function<void()>) = 0;
};

// Impl
class ConsoleImpl : public Console {
public:
  std::vector<std::string> sysArgs() {
    return {};
  }
  void writeStdout(const char *msg) {
    std::cout << msg;
  }
};

class TimerImpl : public Timer {
public:
  TimerImpl(Console &console, Clock &clock) : console_(console), clock_(clock) {}
  void measure(std::function<void()> f) {
    auto start = clock_.getCurrentTime();
    f();
    auto end = clock_.getCurrentTime();
    console_.writeStdout("time: ");
    auto diff = end - start;
    console_.writeStdout("\n");
  }
private:
  Console &console_;
  Clock &clock_;
};

class GreeterImpl {
public:
  GreeterImpl(Console &console) : console_(console) {}
  void greet(std::string &msg) {
    console_.writeStdout("Hello, ");
    console_.writeStdout(msg.c_str());
    console_.writeStdout("!\n");
  }
private:
  Console &console_;
};

class ClockImpl : public Clock {
public:
  double getCurrentTime() {
    return 100;
  }
};

int main() {
  // Wiring
  auto console = ConsoleImpl();
  auto clock = ClockImpl();
  auto greeter = GreeterImpl(console);
  auto timer = TimerImpl(console, clock);
  try {
    timer.measure([&greeter]{
      auto world = std::string("world");
      greeter.greet(world);
    });
  }
  catch (std::exception &e) {
    std::cout << e.what();
  }
  return 0;
}
