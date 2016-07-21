#ifndef _GENE_H_
#define _GENE_H_
#include <vector>
//#include "innovation.h"


class Gene;
class NeuronGene;
class LinkGene;

class Gene {
protected:
  int innovation, id;
public:
  Gene(int);
  int get_innovation();
  int get_id();

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
  std::vector<int> incoming_links;
  std::vector<int> incoming_neurons;
  NeuronGene();
  NeuronGene(int, int, double, double);
  int get_type();
  char* get_type_str();
  void add_incoming_link(int);
  //double get_activation();
  //void set_activation(double);
  double get_pos_x();
  double get_pos_y();
  int get_depth();
};

class LinkGene: public Gene {
  int from, to;
  bool enabled, recurrent;
  double weight;
public:
  LinkGene();
  LinkGene(int, int, int, bool, bool, double);
  bool is_enabled();
  bool is_recurrent();
  void enable();
  void disable();
  double get_weight();
  int get_from_gene();
  int get_to_gene();
};

#endif
