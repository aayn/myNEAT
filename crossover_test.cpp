#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "genome.h"
#include "organism.h"
#include "innovation.h"

using namespace std;
int MAX_NEURONS, INIT_NEURONS;

int main() {
  srand(static_cast<unsigned> (time(0)));
  MAX_NEURONS = 100;
  INIT_NEURONS = 5;
  Organism dog;
  dog.init_pop(2);

  dog.genomes[0].add_init_neuron(0, 0.0f, 0.0f);
  dog.genomes[0].add_init_neuron(0, 1.0f, 0.0f);
  dog.genomes[0].add_init_neuron(1, 0.0f, 1.0f);
  dog.genomes[0].add_init_neuron(1, 0.0f, 1.0f);
  dog.genomes[0].add_init_neuron(1, 0.0f, 1.0f);

  dog.genomes[1].add_init_neuron(0, 0.0f, 0.0f);
  dog.genomes[1].add_init_neuron(0, 1.0f, 0.0f);
  dog.genomes[1].add_init_neuron(1, 0.0f, 1.0f);
  dog.genomes[1].add_init_neuron(1, 0.0f, 1.0f);
  dog.genomes[1].add_init_neuron(1, 0.0f, 1.0f);

  for(int i = 0; i < 40; ++i) {
    dog.genomes[0].mutate_add_axon();
    dog.genomes[0].mutate_add_axon();
    dog.genomes[0].mutate_add_axon();
    dog.genomes[0].mutate_add_neuron();

    dog.genomes[1].mutate_add_axon();
    dog.genomes[1].mutate_add_axon();
    dog.genomes[1].mutate_add_axon();
    dog.genomes[1].mutate_add_neuron();
  }

  dog.genomes[0].print_genome();
  cout << "--------------------------------------------------------------\n\n";
  dog.genomes[1].print_genome();

  cout << "--------------------------------------------------------------\n\n";
  printf("Mom fitness = %lf ; Dad fitness = %lf\n", dog.genomes[0].get_fitness(),
         dog.genomes[1].get_fitness());
  cout << "--------------------------------------------------------------\n\n";

  crossover(dog.genomes[0], dog.genomes[1]).print_genome();

  return 0;
}
