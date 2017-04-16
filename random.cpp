#include<stdlib.h>
#include<time.h>
#include"node.h"
#include"game.h"
#include"random.h"
#include"math.h"

int RANDOM_DECISION(Node *curr)
{
  // return a radomn action from a set of vaild actions in the given state curr.
  char player = curr->PLAYER();
  int * actions,num;
  actions  = curr->ACTIONS();
  srand(time(NULL));
  do {
    num = rand()%9;
  } while(actions[num]!=1);

  return num;
}
