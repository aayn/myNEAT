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
  geno.add_link(1, 2, true, false);
  cout << geno.links[0].get_id() << ", " << geno.links[0].get_weight() << endl;

  geno.add_link(3, 4, true, false);
  cout << geno.links[1].get_id() << ", " << geno.links[1].get_weight() << endl;

  return 0;
}
