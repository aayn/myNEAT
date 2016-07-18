#include "helper.h"
#include <cmath>
#include <cstdlib>

double sigmoid(double t) {
  return 1 / exp(-4.9 * t);
}

double ge1(double v) {
  if(v >= 1)
    return 1.0f;
  return 0.0f;
}

double rand_no(double start, double end) {
  return start + static_cast<double>(rand()) / (static_cast<double> (RAND_MAX /
                                                (end - start)));
}
