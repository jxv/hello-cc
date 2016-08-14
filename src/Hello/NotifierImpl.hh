#ifndef _HELLO_NOTIFIERIMPL_HH_
#define _HELLO_NOTIFIERIMPL_HH_

#include "Hello/Notifier.hh"
#include "Hello/Console.hh"

namespace hello {

class NotifierImpl : public Notifier {
public:
  NotifierImpl(Console &console);
  void timeTaken(double seconds);
private:
  Console &console_;
};

}

#endif
