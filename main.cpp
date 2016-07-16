#include <iostream>
#include "gene.h"

using namespace std;

int main() {
  NeuronGene test_gene(1, 2);
  cout << test_gene.get_innovation_num() << endl;
  cout << test_gene.get_type() << endl;

  LinkGene test_gene2(test_gene, test_gene, true, false, 12.9);
  return 0;
}
