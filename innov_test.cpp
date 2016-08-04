#include <iostream>
#include <vector>
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
  Genome g1(1);
  Genome g2(2);

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

  g1.print_genome();
  cout << "--------------------------------------------------------------\n\n";
  g2.print_genome();

  return 0;
}
