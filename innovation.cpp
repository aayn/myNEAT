#include "innovation.h"

Innovation::Innovation(): prev_inov(0), type(-1) {}

//Innovation::Innovation(int from, int to): {}

int Innovation::new_inov() {
  int t = this->prev_inov++;
  return ++t;
}
