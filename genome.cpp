#include "gene.h"
#include "genome.h"
#include "helper.h"
#include "innovation.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
Innovation idatabase;

Genome::Genome(int x): genome_id(x), prev_axon_id(-1), prev_neuron_id(-1),
                       in_count(0), out_count(0) {}

void Genome::print_genome(){
  for(vector<NeuronGene>::iterator n = neurons.begin(); n != neurons.end(); ++n)
  {
    int ttf = n->get_from_neuron(), ttfi;
    int ttt = n->get_to_neuron(), ttti;
    if(ttf == -1)
      ttfi = 0;
    else
      ttfi = this->neurons[ttf].get_innovation();

      if(ttt == -1)
        ttti = 0;
      else
        ttti = this->neurons[ttt].get_innovation();

    printf("Neuron %d(dY:%lf), type: %s, from: %d(%d), to: %d(%d), innovation: %d\n",
            n->get_id(), n->get_pos_y(), n->get_type_str(), ttf, ttfi,
            ttt, ttti, n->get_innovation());

    for(vector<int>::iterator i = n->incoming_axons.begin();
        i != n->incoming_axons.end(); ++i)
    {
      int tf = this->axons[*i].get_from_neuron();
      int tt = this->axons[*i].get_to_neuron();
      if(this->axons[*i].is_enabled()) {
        printf("%d(%d) ----%d(%d)---> %d(%d)\n", tf,
                                     this->neurons[tf].get_innovation(),
                                     this->axons[*i].get_id(),
                                     this->axons[*i].get_innovation(), tt,
                                     this->neurons[tt].get_innovation());
      }
      else {
        printf("**%d(%d) ----%d(%d)---> %d(%d)**\n", tf,
                                     this->neurons[tf].get_innovation(),
                                     this->axons[*i].get_id(),
                                     this->axons[*i].get_innovation(), tt,
                                     this->neurons[tt].get_innovation());
      }
    }
    printf("\n");
  }
}

void Genome::add_axon(int from, int to, bool en, bool rec) {
  int new_id = 1 + (this->prev_axon_id++);
  double w = rand_no(0, 1);
  int fi = neurons[from].get_innovation();
  int ti = neurons[to].get_innovation();
  int inov = idatabase.assign_innovation(fi, ti, -1);
  AxonGene newAxon(new_id, inov, from, to, en, rec, w);
  this->axons.push_back(newAxon);
  this->neurons[to].incoming_axons.push_back(new_id);
  this->neurons[to].incoming_neurons.push_back(from);
}

void Genome::add_axon(int from, int to, bool en, bool rec, double w) {
  int new_id = 1 + (this->prev_axon_id++);
  int fi = neurons[from].get_innovation();
  int ti = neurons[to].get_innovation();
  int inov = idatabase.assign_innovation(fi, ti, -1);
  AxonGene newAxon(new_id, inov, from, to, en, rec, w);
  this->axons.push_back(newAxon);
  this->neurons[to].incoming_axons.push_back(new_id);
  this->neurons[to].incoming_neurons.push_back(from);
}

void Genome::add_neuron(int type, int from, int to, double x, double y) {
  int new_id = 1 + (this->prev_neuron_id++);
  int fi = neurons[from].get_innovation();
  int ti = neurons[to].get_innovation();
  int inov = idatabase.assign_innovation(fi, ti, 1);
  NeuronGene newNeuron(new_id, inov, from, to, type, x, y);
  this->neurons.push_back(newNeuron);
}

void Genome::add_init_neuron(int type, double x, double y){
  int new_id = 1 + (this->prev_neuron_id++);
  int inov = 1 + new_id; // assign id as innov so that the initial pop has same
                         //innovation numbers across different genomes
  NeuronGene newNeuron(new_id, inov, -1, -1, type, x, y);
  this->neurons.push_back(newNeuron);
}

void Genome::mutate_add_axon() {
  int to = rand() % prev_neuron_id;
  if(neurons[to].get_type() == 0) {
    printf("Can't have a axon to input neuron %d\n", to);
    return;
  }
  int from = rand() % prev_neuron_id;

  if(neurons[from].get_type() == 1) {
    printf("Can't have a axon from output neuron %d\n", from);
    return;
  }

  if(find(this->neurons[to].incoming_neurons.begin(),
          this->neurons[to].incoming_neurons.end(), from) !=
     this->neurons[to].incoming_neurons.end()) {
          printf("Axon from %d to %d already exists.\n", from, to);
          return;
        }
  bool rec = (neurons[from].get_pos_y() >= neurons[to].get_pos_y());
  this->add_axon(from, to, true, rec);
}

void Genome::mutate_add_neuron() {
  const unsigned threshold = 5 + this->in_count + this->out_count;
  int end = axons.size();
  if(axons.size() < threshold)
    end = static_cast<int> (sqrt(axons.size()));
  if(end == 0) {
    cout << "No axons exist for neurons to mutate\n";
    return;
  }
  int mut_axon = rand() % end;
  if(!axons[mut_axon].is_enabled() || axons[mut_axon].is_recurrent())
    return;

  axons[mut_axon].disable();
  int from = axons[mut_axon].get_from_neuron(),
      to = axons[mut_axon].get_to_neuron();

  double new_x = (neurons[from].get_pos_x() + neurons[to].get_pos_x()) / 2,
         new_y = (neurons[from].get_pos_y() + neurons[to].get_pos_y()) / 2;

  this->add_neuron(2, from, to, new_x, new_y);
  //cout << prev_neuron_id << endl;
  //bool rec = (axons[from].get_pos_y() >= axons[prev_axon_id].get_pos_y());
  this->add_axon(from, prev_neuron_id, true, false);
  //bool rec = (axons[prev_axon_id].get_pos_y() >= axons[to].get_pos_y());
  this->add_axon(prev_neuron_id, to, true, false);
}
