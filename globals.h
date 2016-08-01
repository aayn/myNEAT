#ifndef _GLOBALS_H_
#define _GLOBALS_H_

extern double ADD_LINK_PROB, ADD_NEURON_PROB, PERTURB_WEIGHT_PROB,
              ALTER_RESPONSE_PROB;
extern int MAX_NEURONS, INIT_NEURONS;

struct NKey {
  int from, to, type;

  bool operator==(const NKey &t) const {
    return (from == t.from && to == t.to && type==t.type);
  }
};

struct NKeyHasher {
  int operator()(const NKey &n) const {
    return (n.from * MAX_NEURONS + n.to) * n.type;
  }
};

#endif
