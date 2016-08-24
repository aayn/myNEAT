#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "genome.h"
#include "globals.h"
#include "innovation.h"


int MAX_NEURONS, INIT_NEURONS;

using namespace std;

int main() {
  srand(static_cast<unsigned> (time(0)));
  MAX_NEURONS = 100;
  INIT_NEURONS = 5;
  Genome g1;
  Genome g2;

  g1.add_init_neuron(0, 0.0f, 0.0f);
  g1.add_init_neuron(0, 1.0f, 0.0f);
  g1.add_init_neuron(1, 0.0f, 1.0f);
  g1.add_init_neuron(1, 0.0f, 1.0f);
  g1.add_init_neuron(1, 0.0f, 1.0f);

  g2.add_init_neuron(0, 0.0f, 0.0f);
  g2.add_init_neuron(0, 1.0f, 0.0f);
  g2.add_init_neuron(1, 0.0f, 1.0f);
  g2.add_init_neuron(1, 0.0f, 1.0f);
  g2.add_init_neuron(1, 0.0f, 1.0f);

  for(int i = 0; i < 30; ++i) {
    g1.mutate_add_axon();
    g1.mutate_add_axon();
    g1.mutate_add_axon();
    g1.mutate_add_neuron();

    g2.mutate_add_axon();
    g2.mutate_add_axon();
    g2.mutate_add_axon();
    g2.mutate_add_neuron();
  }
  sort(g1.neurons.begin(), g1.neurons.end());
  sort(g2.neurons.begin(), g2.neurons.end());

  sort(g1.axons.begin(), g1.axons.end());
  sort(g2.axons.begin(), g2.axons.end());

  g1.print_genome();
  cout << "--------------------------------------------------------------\n\n";
  g2.print_genome();

  return 0;
}
