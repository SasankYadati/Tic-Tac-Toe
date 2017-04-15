#include<iostream>
#include"node.h"
#include"game.h"
#include"minimax.h"

using namespace std;
int count=0;
int MINIMAX_DECISION(Node curr)
{
  // select the action that leads to a node with highest/lowest minimax-value.
  int *actions = ACTIONS(&curr);
  int decision=0;
  int min_val, max_val, val;

  Node* temp;

  if(PLAYER(&curr)=='X')
    val = -2;
  else
    val = 2;

  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      if(PLAYER(&curr)=='X')
      {
        temp = RESULT(&curr,i);
        min_val = MIN_VALUE(*temp);
        if(val<min_val)
        {
          val = min_val;
          decision = i;
        }
      }
      else
      {
        temp = RESULT(&curr,i);
        max_val = MAX_VALUE(*temp);
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

int MAX_VALUE(Node curr)
{
  count++;
  int v;
  Node* temp;
  int * actions = ACTIONS(&curr);
  if(TERMINAL_TEST(&curr)==true)
  {
    return  UTILITY(&curr,'X');
  }
  v=-2;
  int min_val;

  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      temp = RESULT(&curr,i);
      min_val = MIN_VALUE(*temp);
      if(v < min_val)
        v = min_val;
    }
  }
  return v;
}

int MIN_VALUE(Node curr)
{
  count++;
  int v;
  Node * temp;
  int * actions = ACTIONS(&curr);
  if(TERMINAL_TEST(&curr)==true)
  {
    return UTILITY(&curr,'X');
  }

  v =2;
  int max_val;
  for(int i=0; i<9; ++i)
  {
    if(actions[i]==1)
    {
      temp = RESULT(&curr,i);
      max_val = MAX_VALUE(*temp);
      if(v > max_val)
        v = max_val;
    }
  }
  return v;
}
