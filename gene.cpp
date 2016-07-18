#include "gene.h"
#include <vector>
#include <cstddef>

Gene::Gene(): innovation_num(-1) {}

int Gene::get_innovation_num() {
  return this->innovation_num;
}

LinkGene::LinkGene(): id(-1), from(-1), to(-1), enabled(false),
                      recurrent(false), weight(1.0f) {}
LinkGene::LinkGene(int lid, int from_neuron, int to_neuron, bool en, bool rec,
                   double w): id(lid), from(from_neuron), to(to_neuron),
                   enabled(en), recurrent(rec), weight(w) {}

int LinkGene::get_id() {
   return this->id;
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

int LinkGene::get_from_gene() {
  return this->from;
}

NeuronGene::NeuronGene(): id(-1), type(-1) {}
NeuronGene::NeuronGene(int uid, int t, double act): id(uid), type(t),
                      activation_response(act) {}

int NeuronGene::get_type() {
  return this->type;
}

int NeuronGene::get_id() {
  return this->id;
}

void NeuronGene::add_incoming_link(int link) {
  this->incoming_links.push_back(link);
}

double NeuronGene::get_activation() {
  return this->activation_response;
}

void NeuronGene::set_activation(double v) {
  this->activation_response = v;
}
