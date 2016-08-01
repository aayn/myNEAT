#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "gene.h"
#include "innovation.h"
#include "genome.h"

using namespace std;

int main() {
  srand(static_cast<unsigned> (time(0)));
  Genome geno(1);
  geno.add_neuron(0, -1, -1 0.0f, 0.0f);
  geno.add_neuron(0, -1, -1, 1.0f, 0.0f);
  geno.add_neuron(1, -1 0.0f, 1.0f);
  geno.add_link(1, -1, -1 2, true, false);
  cout << geno.links[0].get_id() << ", " << geno.links[0].get_weight() << endl;
  cout << geno.neurons[2].incoming_neurons[0] << endl;
  geno.mutate_add_neuron();

  cout << geno.neurons[3].incoming_neurons[0] << endl;
  geno.mutate_add_link();

  for(int i = 0; i < 10; ++i) {
    geno.mutate_add_neuron();
    geno.mutate_add_link();
  }

  geno.print_genome();

  //geno.add_link(3, 4, true, false);
  //cout << geno.links[1].get_id() << ", " << geno.links[1].get_weight() << endl;

  //geno.mutate_add_link();
  //cout << geno.links[2].get_id() << ", " << geno.links[2].get_weight() << endl;

  return 0;
}
