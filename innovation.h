#ifndef _INNOVATION_H_
#define _INNOVATION_H_

class Innovation {
  int prev_inov, type; // 0 - link, 1 - neuron, -1 - none
  int from_inov, to_inov; // neurons from and to which the new innovation is
public:
  Innovation();
  //Innovation(int, int); //new link

  int new_inov();
};

#endif
