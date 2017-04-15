#include "node.h"

Node::Node()
{
  //initialize the state of the board
  for(int i=0; i<9; ++i)
  {
    state[i] = ' ';
  }
}
