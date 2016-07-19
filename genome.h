#ifndef _GENOME_H_
#define _GENOME_H_

#include <vector>
#include "gene.h"

using namespace std;

class Genome {
  int genome_id;
  int prev_link_id, prev_neuron_id;
  int in_count, out_count;
public:
  vector<LinkGene> links;
  vector<NeuronGene> neurons;
  Genome(int);
  void add_link(int, int, bool, bool);
  void add_link(int, int, bool, bool, double);
  void add_neuron(int, double, double);

  void mutate_add_link();
  void mutate_add_neuron();
};

#endif
