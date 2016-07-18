#include "gene.h"
#include "genome.h"
#include "helper.h"


Genome::Genome(int x): genome_id(x), prev_link_id(-1), prev_neuron_id(-1) {}

void Genome::add_link(int from, int to, bool en, bool rec) {
  int new_id = 1 + (this->prev_link_id++);
  double w = rand_no(0, 1);
  LinkGene newLink(new_id, from, to, en, rec, w);
  this->links.push_back(newLink);
}

void Genome::add_link(int from, int to, bool en, bool rec, double w) {
  int new_id = 1 + (this->prev_link_id++);
  LinkGene newLink(new_id, from, to, en, rec, w);
  this->links.push_back(newLink);
}
