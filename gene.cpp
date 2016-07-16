#include "gene.h"
#include <cstddef>

Gene::Gene(): innovation_num(-1) {}

NeuronGene::NeuronGene(): id(-1), type(-1) {}
NeuronGene::NeuronGene(int uid, int t): id(uid), type(t) {}

LinkGene::LinkGene(): enabled(false), recurrent(false), weight(1.0f) {}
LinkGene::LinkGene(NeuronGene from, NeuronGene to, bool en, bool rec,
                   double w): from_gene(&from), to_gene(&to), enabled(en),
                   recurrent(rec), weight(w) {}

int Gene::get_innovation_num() {
  return this->innovation_num;
}

bool LinkGene::is_enabled() {
  return this->enabled;
}

bool LinkGene::is_recurrent() {
  return this->recurrent;
}

void LinkGene::enable() {
  this->enabled = true;
}

void LinkGene::disable() {
  this->enabled = false;
}

double LinkGene::get_weight() {
  return this->weight;
}

int NeuronGene::get_type() {
  return this->type;
}
