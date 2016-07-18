#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "gene.h"
#include "helper.h"

using namespace std;

int main() {
  vector<NeuronGene> neurons;
  vector<LinkGene> links;

  NeuronGene in1(0, 0, 1.0f);
  NeuronGene in2(1, 0, 1.0f);
  NeuronGene h1(2, 2, 0.0f);
  NeuronGene h2(3, 2, 0.0f);
  NeuronGene o1(4, 1, 0.0f);

  LinkGene l02(0, 0, 2, true, false, 0.5f);
  links.push_back(l02);
  h1.add_incoming_link(0);

  LinkGene l03(1, 0, 3, true, false, 1.0f);
  links.push_back(l03);
  h2.add_incoming_link(1);

  LinkGene l12(2, 1, 1, true, false, 0.5f);
  links.push_back(l12);
  h1.add_incoming_link(2);

  LinkGene l13(3, 1, 3, true, false, 1.0f);
  links.push_back(l13);
  h2.add_incoming_link(3);

  LinkGene l24(4, 2, 4, true, false, -2.0f);
  links.push_back(l24);
  o1.add_incoming_link(4);

  LinkGene l34(5, 3, 4, true, false, 1.0f);
  links.push_back(l34);
  o1.add_incoming_link(5);

  sort(links.begin(), links.end());

  neurons.push_back(in1);
  neurons.push_back(in2);
  neurons.push_back(h1);
  neurons.push_back(h2);
  neurons.push_back(o1);

  sort(neurons.begin(), neurons.end());

  for (vector<NeuronGene>::iterator i = neurons.begin(); i != neurons.end();
       ++i)
  {
    if(i->get_type() == 0)
      continue;
    double sum = 0, tw = 0, in_val = 0;
    int from_n = 0;
    for (vector<int>::iterator j = i->incoming_links.begin();
         j != i->incoming_links.end(); ++j) {
           tw = links[*j].get_weight();
           from_n = links[*j].get_from_gene();
           in_val = neurons[from_n].get_activation();
           sum += in_val * tw;
    }
    i->set_activation(ge1(sum));
  }

  for (vector<NeuronGene>::iterator i = neurons.begin(); i != neurons.end(); ++i)
  {
    cout << i->get_id() << ", " << i->get_activation() << endl;
  }


  return 0;
}
