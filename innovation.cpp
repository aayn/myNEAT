#include "innovation.h"
#include "globals.h"

Innovation::Innovation(): cur_neuron_inov(5 + 1), cur_axon_inov(MAX_NEURONS + 1) {}

int Innovation::inov_exists(int fi, int ti, int type) {// type: neuron(1) axon(-1)
  if(fi == -1 && ti == -1)
    return 0;
  NKey ipair = {fi, ti, type};
  itemp = idata[ipair];
  if((type == 1 && itemp > MAX_NEURONS) || (type == -1 && itemp < MAX_NEURONS))
    return 0;
  return itemp;
}

int Innovation::assign_innovation(int fi, int ti, int type) {
  atemp = inov_exists(fi, ti, type);
  if(atemp == 0) {
    NKey ipair = {fi, ti, type};
    if(type == 1){
      if(fi != -1)
        idata[ipair] = cur_neuron_inov;
      cur_neuron_inov++;
      return cur_neuron_inov - 1;
    }
    else {
      if(fi != -1)
        idata[ipair] = cur_axon_inov + MAX_NEURONS;
      cur_axon_inov++;
      return cur_axon_inov - 1 + MAX_NEURONS;
    }
  }
  return atemp;
}
