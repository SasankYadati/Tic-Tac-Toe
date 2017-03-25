#include"node.h"
#include"game.h"

Node* RESULT(Node* curr, int action)
{
  //return the new node which is the result is of taking action in curr.
  Node * next;
  next = new Node;

  //copy the curr state to next state.
  for(int i=0; i<9; ++i)
  {
    next->state[i] = curr->state[i];
  }

  //update the new cell in the next state.
  if(curr->PLAYER()=='X')
  {
    next->state[action] = 'X';
  }
  else
  {
    next->state[action] = 'O';
  }

  return next;
}

bool TERMINAL_TEST(Node* curr)
{
  for(int i=0; i<=6; i+=3)
  {
    if( curr->state[i] != ' ' && curr->state[i] == curr->state[i+1] && curr->state[i+1] == curr->state[i+2] )
    {
      return true; //one of the rows matched
    }
  }

  for(int j=0; j<=2; j++)
  {
    if( curr->state[j] != ' ' && curr->state[j] == curr->state[j+3] && curr->state[j+3] == curr->state[j+6] )
    {
      return true; //one of the cols matched
    }
  }


  if( curr->state[0] != ' ' && curr->state[0] == curr->state[4] && curr->state[4] == curr->state[8] )
  {
    return true; // the principle diagonal
  }

  if( curr->state[2] != ' ' && curr->state[2] == curr->state[4] && curr->state[4] == curr->state[6] )
  {
    return true; // the other diagonal
  }

  return false; // not a terminal state
}

int UTILITY(Node* curr, char player='X')
{
  //return the score for player in curr state (terminal state).
  if(player=='X')
  {
    

  }
  else
  {

  }

}
