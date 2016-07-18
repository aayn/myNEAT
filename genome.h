#ifndef _GENOME_H_
#define _GENOME_H_

#include <vector>
#include "gene.h"

using namespace std;

class Genome {
  int genome_id;
  int prev_link_id, prev_neuron_id;
public:
  vector<LinkGene> links;
  vector<NeuronGene> neurons;
  Genome(int);
  void add_link(int, int, bool, bool);
  void add_link(int, int, bool, bool, double);
};

#endif
