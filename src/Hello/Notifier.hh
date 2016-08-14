#ifndef _HELLO_NOTIFIER_HH_
#define _HELLO_NOTIFIER_HH_

namespace hello {

class Notifier {
public:
  virtual void timeTaken(double seconds) = 0;
};

}

#endif
