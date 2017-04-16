#ifndef NODE_H
#define NODE_H

class Node{

public:
  char state[9]; //board's configuration

  Node(); //node constructor
  char PLAYER(); //return an 'X' or an 'O'
  int* ACTIONS(); //returns an array indicating all the possible actions

};

#endif
