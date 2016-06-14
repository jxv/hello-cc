#include <iostream>
#include <string>
#include <vector>
#include <functional>

class FileSystem {
public:
  virtual std::string read_file(std::string &path) = 0;
};

class Console {
public:
  virtual std::vector<std::string> sys_args() = 0;
  virtual void write_stdout(const char *) = 0;
};

class Clock {
public:
  virtual double get_current_time() = 0;
};

class Configuration {
public:
  virtual std::string target() = 0;
};

class Exit {
public:
  virtual void error_exit(std::string &msg) = 0;
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
  std::vector<std::string> sys_args() {
    return {};
  }
  void write_stdout(const char *msg) {
    std::cout << msg;
  }
};

class TimerImpl : public Timer {
public:
  TimerImpl(Console &console, Clock &clock) : console_(console), clock_(clock) {}
  void measure(std::function<void()> f) {
    auto start = clock_.get_current_time();
    f();
    auto end = clock_.get_current_time();
    console_.write_stdout("time: ");
    auto diff = end - start;
    console_.write_stdout("\n");
  }
private:
  Console &console_;
  Clock &clock_;
};

class GreeterImpl {
public:
  GreeterImpl(Console &console) : console_(console) {}
  void greet(std::string &msg) {
    console_.write_stdout("Hello, ");
    console_.write_stdout(msg.c_str());
    console_.write_stdout("!\n");
  }
private:
  Console &console_;
};

class ClockImpl : public Clock {
public:
  double get_current_time() {
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
