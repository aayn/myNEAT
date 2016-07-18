#include "helper.h"
#include <cmath>

double sigmoid(double t) {
  return 1 / exp(-4.9 * t);
}

double ge1(double v) {
  if(v >= 1)
    return 1.0f;
  return 0.0f;
}
