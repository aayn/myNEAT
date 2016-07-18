#include "helper.h"
#include <cmath>

double sigmoid(double t, double beta = 4.9f) {
  return 1 / exp(-beta * t);
}

double ge1(double v) {
  if(v >= 1)
    return 1.0f;
  return 0.0f;
}
