#include "node.h"

Node::Node()
{
  //initialize the state of the board
  for(int i=0; i<9; ++i)
  {
    state[i] = ' ';
  }
}

char Node::PLAYER()
{
  //count no. of X's and O's to determine the player's turn.
  int x_count=0;
  int o_count=0;

  for(int i=0;i<9;++i)
  {
    if(state[i]=='X')
    {
      x_count++;
    }
    else if(state[i]=='O')
    {
      o_count++;
    }
  }

  if(x_count == o_count)
  {
    return 'X';
  }
  else
  {
    return 'O';
  }
}

int* Node::ACTIONS()
{
  // returns an array actions[] where each index represents the corresponding cell in the board
  // and the value is one if the cell is empty,
  // 0 otherwise.
  int * actions;
  actions = new int[9];
  for(int i=0; i<9; ++i)
  {
    actions[i] = 0;
    if(state[i] == ' ')
    {
      actions[i] = 1;
    }
  }
  return actions;
}
