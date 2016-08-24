#include <iostream>
#include <vector>
#include <algorithm>
#include "organism.h"
#include "gene.h"
#include "genome.h"

using namespace std;

double Organism::compat_score(Genome a, Genome b) {
  return 0.0f;
}

Genome crossover(Genome mom, Genome dad) {
/*sort(mom.neurons.begin(), mom.neurons.end());
  sort(dad.neurons.begin(), dad.neurons.end());
  sort(mom.axons.begin(), dad.axons.end());
  sort(dad.axons.begin(), dad.axons.end()); */

  //Neurons
  vector<NeuronGene>::iterator nm = mom.neurons.begin();
  vector<NeuronGene>::iterator nd = dad.neurons.begin();

  Genome child;

  while(nm != mom.neurons.end() && nd != dad.neurons.end()) {

    if(nm->get_innovation() < nd->get_innovation()) {
      //disjoint/excess neurons of mom
      if(mom.get_fitness() > dad.get_fitness()) {
        child.add_neuron(nm->get_type(), nm->get_from_neuron(),
                         nm->get_to_neuron(), nm->get_pos_x(), nm->get_pos_y(),
                         nm->get_innovation());
      }
      ++nm;
    }
    else if(nd->get_innovation() < nm->get_innovation()) {
      //disjoint/excess neurons neurons of dad
      if(dad.get_fitness() > mom.get_fitness()) {
        child.add_neuron(nd->get_type(), nd->get_from_neuron(),
                         nd->get_to_neuron(), nd->get_pos_x(), nd->get_pos_y(),
                         nd->get_innovation());
      }
      ++nd;
    }
    else {
      //matching neurons
      child.add_neuron(nm->get_type(), nm->get_from_neuron(),
                       nm->get_to_neuron(), nm->get_pos_x(), nm->get_pos_y(),
                       nm->get_innovation());
      ++nm;
      ++nd;
    }
  }

  if(nm != mom.neurons.end() && mom.get_fitness() >= dad.get_fitness()) {
    while(nm != mom.neurons.end()) {
      child.add_neuron(nm->get_type(), nm->get_from_neuron(),
                       nm->get_to_neuron(), nm->get_pos_x(), nm->get_pos_y(),
                       nm->get_innovation());
      ++nm;
    }
  }

  if(nd != dad.neurons.end() && dad.get_fitness() >= mom.get_fitness()) {
    while(nd != dad.neurons.end()) {
      child.add_neuron(nd->get_type(), nd->get_from_neuron(),
                       nd->get_to_neuron(), nd->get_pos_x(), nd->get_pos_y(),
                       nd->get_innovation());
      ++nd;
    }
  }

  // Axons
  vector<AxonGene>::iterator am = mom.axons.begin();
  vector<AxonGene>::iterator ad = dad.axons.begin();

  while(am != mom.axons.end() && ad != dad.axons.end()) {

    if(am->get_innovation() < ad->get_innovation()) {
      //disjoint/excess neurons of mom
      if(mom.get_fitness() > dad.get_fitness()) {
        child.add_axon(am->get_from_neuron(), am->get_to_neuron(),
                       am->is_enabled(), am->is_recurrent(),
                       am->get_innovation());
      }
      ++am;
    }
    else if(ad->get_innovation() < am->get_innovation()) {
      //disjoint/excess neurons neurons of dad
      if(dad.get_fitness() > mom.get_fitness()) {
        child.add_axon(ad->get_from_neuron(), ad->get_to_neuron(),
                       ad->is_enabled(), ad->is_recurrent(),
                       ad->get_innovation());
      }
      ++ad;
    }
    else {
      //matching neurons
      //change the line below to random later
      bool en = (ad->is_enabled() && am->is_enabled());
      child.add_axon(ad->get_from_neuron(), ad->get_to_neuron(), en,
                     ad->is_recurrent(), ad->get_innovation());
      ++am;
      ++ad;
    }
  }

  if(am != mom.axons.end() && mom.get_fitness() >= dad.get_fitness()) {
    while(am != mom.axons.end()) {
      child.add_axon(am->get_from_neuron(), am->get_to_neuron(),
                     am->is_enabled(), am->is_recurrent(),
                     am->get_innovation());
      ++am;
    }
  }

  if(ad != dad.axons.end() && dad.get_fitness() >= mom.get_fitness()) {
    while(ad != dad.axons.end()) {
      child.add_axon(ad->get_from_neuron(), ad->get_to_neuron(),
                     ad->is_enabled(), ad->is_recurrent(),
                     ad->get_innovation());
      ++ad;
    }
  }
  return child;
}

void Organism::init_pop(int i) {
  this->genomes.resize(i);
}
