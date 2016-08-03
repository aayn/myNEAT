#ifndef _GENE_H_
#define _GENE_H_
#include <vector>
//#include "innovation.h"


class Gene;
class NeuronGene;
class AxonGene;

class Gene {
protected:
  int id, innovation;
  int from, to;
public:
  Gene(int, int, int, int);
  int get_innovation();
  int get_id();
  int get_from_neuron();
  int get_to_neuron();

  bool operator < (const Gene &n) const {
    return (id < n.id);
  }
};

class NeuronGene: public Gene {
  int type, depth;
  char t[10];  // -1 - none, 0 - input, 1 - output, 2 - hidden
  //double activation_response;
  double pos_x, pos_y; // between 0 and 1 both inclusive
public:
  std::vector<int> incoming_axons;
  std::vector<int> incoming_neurons;
  NeuronGene();
  NeuronGene(int, int, int, int, int, double, double);
  int get_type();
  char* get_type_str();
  void add_incoming_axon(int);
  //double get_activation();
  //void set_activation(double);
  double get_pos_x();
  double get_pos_y();
  int get_depth();
};

class AxonGene: public Gene {
  bool enabled, recurrent;
  double weight;
public:
  AxonGene();
  AxonGene(int, int, int, int, bool, bool, double);
  bool is_enabled();
  bool is_recurrent();
  void enable();
  void disable();
  double get_weight();
};

#endif
