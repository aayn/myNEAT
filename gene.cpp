#include "gene.h"
#include "helper.h"
#include <vector>
#include <cstddef>
#include <cstring>

Gene::Gene(int x, int i, int f, int t): id(x), innovation(i), from(f), to(t) {}

int Gene::get_innovation() {
  return this->innovation;
}

int Gene::get_id() {
   return this->id;
}

int Gene::get_from_neuron() {
  return this->from;
}

int Gene::get_to_neuron() {
  return this->to;
}

AxonGene::AxonGene(): Gene(-1, -1, -1, -1), enabled(false), recurrent(false),
                      weight(1.0f) {}

AxonGene::AxonGene(int lid, int ino, int from_neuron, int to_neuron, bool en,
                   bool rec,double w): Gene(lid, ino, from_neuron, to_neuron),
                   enabled(en), recurrent(rec), weight(w) {}

bool AxonGene::is_enabled() {
  return this->enabled;
}

bool AxonGene::is_recurrent() {
  return this->recurrent;
}

void AxonGene::enable() {
  this->enabled = true;
}

void AxonGene::disable() {
  this->enabled = false;
}

double AxonGene::get_weight() {
  return this->weight;
}

NeuronGene::NeuronGene(): Gene(-1, -1, -1, -1), type(-1) {}
NeuronGene::NeuronGene(int uid, int ino, int from, int to, int t, double x,
                       double y): Gene(uid, ino, from, to), type(t), pos_x(x),
                                  pos_y(y) {}

int NeuronGene::get_type() {
  return this->type;
}

char* NeuronGene::get_type_str() {
  switch (this->type) {
    case -1: strcpy(t, "none"); break;
    case 0: strcpy(t, "input"); break;
    case 1: strcpy(t, "output"); break;
    case 2: strcpy(t, "hidden"); break;
  }
  return t;
}

void NeuronGene::add_incoming_axon(int axon) {
  this->incoming_axons.push_back(axon);
}
/*
double NeuronGene::get_activation() {
  return this->activation_response;
}

if(check_if_integral(t))
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

int NeuronGene::get_depth() {
  double t = this->pos_y;
  this->depth = 0;
  while(true) {
      break;
    t *= 2;
    this->depth++;
  }
  return this->depth;
}
