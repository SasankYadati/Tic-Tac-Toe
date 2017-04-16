#include"node.h"
#include"game.h"
#include"minimax.h"

int MINIMAX_DECISION(Node *curr)
{
  // select the action that leads to a node with highest/lowest minimax-value.
  int *actions = curr->ACTIONS();
  int decision=0;
  int min_val, max_val, val;

  Node* temp;

  if(curr->PLAYER()=='X')
    val = -2;
  else
    val = 2;

  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      if(curr->PLAYER()=='X')
      {
        temp = RESULT(curr,i);
        min_val = MIN_VALUE(temp);
        if(val<min_val)
        {
          val = min_val;
          decision = i;
        }
      }
      else
      {
        temp = RESULT(curr,i);
        max_val = MAX_VALUE(temp);
        if(val>max_val)
        {
          val = max_val;
          decision = i;
        }
      }
    }
  }

  return decision;
}

int MAX_VALUE(Node *curr)
{
  int v;
  Node* temp;
  int * actions = curr->ACTIONS();
  if(TERMINAL_TEST(curr)==true)
  {
    v = UTILITY(curr,'X');
    delete curr;
    return  v;
  }
  v=-2;
  int min_val;

  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      temp = RESULT(curr,i);
      min_val = MIN_VALUE(temp);
      if(v < min_val)
        v = min_val;
    }
  }
  delete curr;
  return v;
}

int MIN_VALUE(Node *curr)
{
  int v;
  Node * temp;
  int * actions = curr->ACTIONS();
  if(TERMINAL_TEST(curr)==true)
  {
    v = UTILITY(curr,'X');
    delete curr;
    return  v;
  }

  v =2;
  int max_val;
  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      temp = RESULT(curr,i);
      max_val = MAX_VALUE(temp);
      if(v > max_val)
        v = max_val;
    }
  }
  delete curr;
  return v;
}
