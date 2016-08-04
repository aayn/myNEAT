#include <vector>
#include "genome.h"
#include "innovation.h"

class Organism {
  vector<Genome> genomes;
public:
  double compat_score(genome, genome);
  genome crossover(genome, genome);
};
