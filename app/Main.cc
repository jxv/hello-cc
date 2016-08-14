#include "Hello/FileSystemImpl.hh"
#include "Hello/ConsoleImpl.hh"
#include "Hello/ClockImpl.hh"
#include "Hello/ConfigurationImpl.hh"
#include "Hello/GreeterImpl.hh"
#include "Hello/TimerImpl.hh"
#include "Hello/NotifierImpl.hh"
#include "Hello/Main.hh"

int main(int argc, const char **argv) {
  auto console = hello::ConsoleImpl(argc, argv);
  auto fileSystem = hello::FileSystemImpl();
  auto configuration = hello::ConfigurationImpl(console, fileSystem);
  auto clock = hello::ClockImpl();
  auto greeter = hello::GreeterImpl(console);
  auto notifier = hello::NotifierImpl(console);
  auto timer = hello::TimerImpl(notifier, clock);

  return hello::main(timer, greeter, configuration);
}
