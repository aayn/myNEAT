#ifndef _GENE_H_
#define _GENE_H_

class Gene {
protected:
  int innovation_num;
public:
  int get_innovation_num();
  Gene();
};

class NeuronGene: public Gene {
  int id, type; // -1 - none, 0 - input, 1 - output, 2 - hidden, 3 - bias
public:
  NeuronGene();
  NeuronGene(int, int);
  int get_type();
};

class LinkGene: public Gene {
  NeuronGene *from_gene, *to_gene;
  bool enabled, recurrent;
  double weight;
public:
  LinkGene();
  LinkGene(NeuronGene, NeuronGene, bool, bool, double);
  bool is_enabled();
  bool is_recurrent();
  void enable();
  void disable();
  double get_weight();
};

#endif
