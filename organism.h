#include <vector>
#include "genome.h"
#include "innovation.h"

class Organism {
public:
  vector<Genome> genomes;
  double compat_score(Genome, Genome);
  void init_pop(int);

  //Genome operator[](int i) const {
  //  return this->genomes[i];
  //}
};

Genome crossover(Genome, Genome);
