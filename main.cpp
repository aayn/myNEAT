#include <iostream>
#include "gene.h"
#include "helper.h"

using namespace std;

typedef pair<int, NeuronGene> ng_pair;

int main() {
  vector<ng_pair> neurons;
  vector<LinkGene> links;



  NeuronGene test_gene(1, 2);
  cout << test_gene.get_innovation_num() << endl;
  cout << test_gene.get_type() << endl;

  LinkGene test_gene2(test_gene, test_gene, true, false, 12.9);
  return 0;
}
