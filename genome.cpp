#include "gene.h"
#include "genome.h"
#include "helper.h"
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

Genome::Genome(int x): genome_id(x), prev_link_id(-1), prev_neuron_id(-1),
                       in_count(0), out_count(0) {}

void Genome::add_link(int from, int to, bool en, bool rec) {
  int new_id = 1 + (this->prev_link_id++);
  double w = rand_no(0, 1);
  LinkGene newLink(new_id, from, to, en, rec, w);
  this->links.push_back(newLink);
  this->neurons[to].incoming_links.push_back(new_id);
  this->neurons[to].incoming_neurons.push_back(from);
}

void Genome::add_link(int from, int to, bool en, bool rec, double w) {
  int new_id = 1 + (this->prev_link_id++);
  LinkGene newLink(new_id, from, to, en, rec, w);
  this->links.push_back(newLink);
  this->neurons[to].incoming_links.push_back(new_id);
  this->neurons[to].incoming_neurons.push_back(from);
}

void Genome::add_neuron(int type, double x, double y) {
  int new_id = 1 + (this->prev_neuron_id++);
  NeuronGene newNeuron(new_id, type, x, y);
  this->neurons.push_back(newNeuron);
}

void Genome::mutate_add_link() {
  int to = rand() % prev_neuron_id;
  if(neurons[to].get_type() == 0) {
    printf("Can't have a link to input neuron %d\n", to);
    return;
  }
  int from = rand() % prev_neuron_id;
  if(find(this->neurons[to].incoming_neurons.begin(),
          this->neurons[to].incoming_neurons.end(), from) ==
     this->neurons[to].incoming_neurons.end()) {
          printf("Link from %d to %d already exists.\n", from, to);
          return;
        }
  bool rec = (neurons[from].get_pos_y() >= neurons[to].get_pos_y());
  this->add_link(from, to, true, rec);
}

void Genome::mutate_add_neuron() {
  const unsigned threshold = 5 + this->in_count + this->out_count;
  int end = links.size();
  if(links.size() < threshold)
    end = static_cast<int> (sqrt(links.size()));
  int mut_link = rand() % end;
  if(!links[mut_link].is_enabled() || links[mut_link].is_recurrent())
    return;

  links[mut_link].disable();
  int from = links[mut_link].get_from_gene(),
      to = links[mut_link].get_to_gene();
  double new_x = (neurons[from].get_pos_x() + neurons[to].get_pos_x()) / 2,
         new_y = (neurons[from].get_pos_y() + neurons[to].get_pos_y()) / 2;

  this->add_neuron(2, new_x, new_y);
  //bool rec = (links[from].get_pos_y() >= links[prev_link_id].get_pos_y());
  this->add_link(from, prev_link_id, true, false);
  //bool rec = (links[prev_link_id].get_pos_y() >= links[to].get_pos_y());
  this->add_link(prev_link_id, to, true, false);
}
