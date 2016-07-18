#include <vector>
#ifndef _GENE_H_
#define _GENE_H_

class Gene;
class NeuronGene;
class LinkGene;

class Gene {
protected:
  int innovation_num;
public:
  Gene();
  int get_innovation_num();
};

class NeuronGene: public Gene {
  int id, type; // -1 - none, 0 - input, 1 - output, 2 - hidden, 3 - bias
  double activation_response;
public:
  std::vector<int> incoming_links;
  NeuronGene();
  NeuronGene(int, int, double);
  int get_id();
  int get_type();
  void add_incoming_link(int);
  double get_activation();
  void set_activation(double);

  bool operator < (const NeuronGene &n) const {
    return (id < n.id);
  }

};

class LinkGene: public Gene {
  int id, from, to;
  bool enabled, recurrent;
  double weight;
public:
  LinkGene();
  LinkGene(int, int, int, bool, bool, double);
  int get_id();
  bool is_enabled();
  bool is_recurrent();
  void enable();
  void disable();
  double get_weight();
  int get_from_gene();

  bool operator < (const LinkGene &n) const {
    return (id < n.id);
  }
};

#endif
