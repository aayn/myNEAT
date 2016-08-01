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

Genome::Genome(int x): genome_id(x), prev_link_id(-1), prev_neuron_id(-1),
                       in_count(0), out_count(0) {}

void Genome::print_genome(){
  for(vector<NeuronGene>::iterator n = neurons.begin(); n != neurons.end(); ++n)
  {
    int ttf = n->get_from_neuron();
    int ttt = n->get_to_neuron();
    printf("Neuron %d(dY:%lf), type: %s, from: %d(%d), to: %d(%d), innovation: %d\n",
            n->get_id(), n->get_pos_y(), n->get_type_str(), ttf,
            this->neurons[ttf].get_innovation(), ttt,
            this->neurons[ttt].get_innovation(), n->get_innovation());

    for(vector<int>::iterator i = n->incoming_links.begin();
        i != n->incoming_links.end(); ++i)
    {
      int tf = this->links[*i].get_from_neuron();
      int tt = this->links[*i].get_to_neuron();
      if(this->links[*i].is_enabled()) {
        printf("%d(%d) ----%d(%d)---> %d(%d)\n", tf,
                                     this->neurons[tf].get_innovation(),
                                     this->links[*i].get_id(),
                                     this->links[*i].get_innovation(), tt,
                                     this->neurons[tt].get_innovation());
      }
      else {
        printf("**%d(%d) ----%d(%d)---> %d(%d)**\n", tf,
                                     this->neurons[tf].get_innovation(),
                                     this->links[*i].get_id(),
                                     this->links[*i].get_innovation(), tt,
                                     this->neurons[tt].get_innovation());
      }
    }
    printf("\n");
  }
}

void Genome::add_link(int from, int to, bool en, bool rec) {
  int new_id = 1 + (this->prev_link_id++);
  double w = rand_no(0, 1);
  int fi = neurons[from].get_innovation();
  int ti = neurons[to].get_innovation();
  int inov = idatabase.assign_innovation(fi, ti, -1);
  LinkGene newLink(new_id, inov, from, to, en, rec, w);
  this->links.push_back(newLink);
  this->neurons[to].incoming_links.push_back(new_id);
  this->neurons[to].incoming_neurons.push_back(from);
}

void Genome::add_link(int from, int to, bool en, bool rec, double w) {
  int new_id = 1 + (this->prev_link_id++);
  int fi = neurons[from].get_innovation();
  int ti = neurons[to].get_innovation();
  int inov = idatabase.assign_innovation(fi, ti, -1);
  LinkGene newLink(new_id, inov, from, to, en, rec, w);
  this->links.push_back(newLink);
  this->neurons[to].incoming_links.push_back(new_id);
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

void Genome::mutate_add_link() {
  int to = rand() % prev_neuron_id;
  if(neurons[to].get_type() == 0) {
    printf("Can't have a link to input neuron %d\n", to);
    return;
  }
  int from = rand() % prev_neuron_id;

  if(neurons[from].get_type() == 1) {
    printf("Can't have a link from output neuron %d\n", from);
    return;
  }

  if(find(this->neurons[to].incoming_neurons.begin(),
          this->neurons[to].incoming_neurons.end(), from) !=
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
  if(end == 0) {
    cout << "No links exist for neurons to mutate\n";
    return;
  }
  int mut_link = rand() % end;
  if(!links[mut_link].is_enabled() || links[mut_link].is_recurrent())
    return;

  links[mut_link].disable();
  int from = links[mut_link].get_from_neuron(),
      to = links[mut_link].get_to_neuron();

  double new_x = (neurons[from].get_pos_x() + neurons[to].get_pos_x()) / 2,
         new_y = (neurons[from].get_pos_y() + neurons[to].get_pos_y()) / 2;

  this->add_neuron(2, from, to, new_x, new_y);
  //cout << prev_neuron_id << endl;
  //bool rec = (links[from].get_pos_y() >= links[prev_link_id].get_pos_y());
  this->add_link(from, prev_neuron_id, true, false);
  //bool rec = (links[prev_link_id].get_pos_y() >= links[to].get_pos_y());
  this->add_link(prev_neuron_id, to, true, false);
}
