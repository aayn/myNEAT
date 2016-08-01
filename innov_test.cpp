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
  vector<Genome> genomes;
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

  for(int i = 0; i < 10; ++i) {
    g1.mutate_add_link();
    g1.mutate_add_link();
    g1.mutate_add_link();
    g1.mutate_add_link();
    g1.mutate_add_neuron();

    g2.mutate_add_link();
    g2.mutate_add_link();
    g2.mutate_add_link();
    g2.mutate_add_link();
    g2.mutate_add_neuron();
  }
  g1.print_genome();
  cout << "--------------------------------------------------------------\n\n";
  g2.print_genome();

  return 0;
}
