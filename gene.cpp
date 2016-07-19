#include "gene.h"
#include <vector>
#include <cstddef>

Gene::Gene(int x): id(x) {}

int Gene::get_innovation_num() {
  return this->innovation_num;
}

int Gene::get_id() {
   return this->id;
}

LinkGene::LinkGene(): Gene(-1), from(-1), to(-1), enabled(false),
                      recurrent(false), weight(1.0f) {}
LinkGene::LinkGene(int lid, int from_neuron, int to_neuron, bool en, bool rec,
                   double w): Gene(lid), from(from_neuron), to(to_neuron),
                   enabled(en), recurrent(rec), weight(w) {}

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

int LinkGene::get_to_gene() {
  return this->to;
}

NeuronGene::NeuronGene(): Gene(-1), type(-1) {}
NeuronGene::NeuronGene(int uid, int t, double x, double y):
                       Gene(uid), type(t), pos_x(x), pos_y(y) {}

int NeuronGene::get_type() {
  return this->type;
}

void NeuronGene::add_incoming_link(int link) {
  this->incoming_links.push_back(link);
}
/*
double NeuronGene::get_activation() {
  return this->activation_response;
}

void NeuronGene::set_activation(double v) {
  this->activation_response = v;
}
*/
double NeuronGene::get_pos_y() {
  return this->pos_y;
}

double NeuronGene::get_pos_x() {
  return this->pos_x;
}
