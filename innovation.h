#ifndef _INNOVATION_H_
#define _INNOVATION_H_

#include <utility>
#include <vector>
#include <unordered_map>
#include "globals.h"

using namespace std;

class Innovation {
  //Neuron innnovation number will start from 1 to say 10^7. Axon innovation no.
  //will start from 10^7 + 1 to MAX_INT
  int cur_neuron_inov, cur_axon_inov, itemp, atemp;
  unordered_map<NKey, int, NKeyHasher> idata; // neurons from and to which the
                                             //new innovation is
public:
  Innovation();
  int inov_exists(int, int, int);
  int assign_innovation(int, int, int);
};

extern Innovation idatabase;

#endif
