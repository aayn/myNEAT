#ifndef _GENOME_H_
#define _GENOME_H_

#include <vector>
#include "gene.h"

using namespace std;

class Genome {
  int genome_id;
  int prev_axon_id, prev_neuron_id;
  int in_count, out_count;
public:
  vector<AxonGene> axons;
  vector<NeuronGene> neurons;
  Genome(int);
  void print_genome();
  void add_axon(int, int, bool, bool);
  void add_axon(int, int, bool, bool, double);
  void add_neuron(int, int, int, double, double);
  void add_init_neuron(int, double, double);

  void mutate_add_axon();
  void mutate_add_neuron();
};

#endif
