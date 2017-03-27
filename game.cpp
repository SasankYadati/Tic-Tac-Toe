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
    return true; // the principal diagonal
  }

  if( curr->state[2] != ' ' && curr->state[2] == curr->state[4] && curr->state[4] == curr->state[6] )
  {
    return true; // the other diagonal
  }

  return false; // not a terminal state
}

int UTILITY(Node* curr, char player='X')
{
  //return the score for player in the state curr.
  //assumes curr is a terminal state.
  //will return either +1, -1 or 0.


  if(player=='X')// utility for player X
  {
    for(int i=0; i<=6; i+=3)// all the rows!
    {
      if(curr->state[i] != ' ' && curr->state[i]==curr->state[i+1] && curr->state[i+1]==curr->state[i+2])
      {
        if(curr->state[i]=='X')
        {
          return 1;// +1 to X because we found three X's in the row starting with index i.
        }
        else
        {
          return -1;// -1 to X because we found three O's in the row starting with index i.
        }
      }

      for(int i=0; i<=2; i++)// all the columns!
      {
        if(curr->state[i] != ' ' && curr->state[i]==curr->state[i+3] && curr->state[i+3]==curr->state[i+6])
        {
          if(curr->state[i]=='X')
          {
            return 1;// +1 to X because we found three X's in the column starting with index i.
          }
          else
          {
            return -1;// -1 to X because we found three O'x in the column starting with index i.
          }
        }

      }

      // finished checking the rows and the columns
      // now we need to check the diagonals

      //diagonal one
      if(curr->state[0]!=' ' && curr->state[0]==curr->state[4] && curr->state[4]==curr->state[8])
      {
        if(curr->state[0] == 'X')
          return 1; // +1 to X because we found three X's in the principal diagonal
        else
          return -1; // -1 to X because we found three O's in the principal diagonal
      }

      //diagonal two
      if(curr->state[2]!=' ' && curr->state[2]==curr->state[4] && curr->state[4]== curr->state[6])
      {
        if(curr->state[2] == 'X')
          return 1; // +1 to X because we found three X's in the secondary diagonal
        else
          return -1;// -1 to X because we found three O's in the secondary diagonal
      }
    }
    // if the execution has come up to this pointer
    // it means we found no win-lose situation
    return 0;
    //hence is a draw situation
  }


  else// utility for player O
  {
    for(int i=0; i<=6; i+=3)// all the rows!
    {
      if(curr->state[i] != ' ' && curr->state[i]==curr->state[i+1] && curr->state[i+1]==curr->state[i+2])
      {
        if(curr->state[i]=='O')
        {
          return 1;// +1 to O because we found three O's in the row starting with index i.
        }
        else
        {
          return -1;// -1 to O because we found three X's in the row starting with index i.
        }
      }

      for(int i=0; i<=2; i++)// all the columns!
      {
        if(curr->state[i] != ' ' && curr->state[i]==curr->state[i+3] && curr->state[i+3]==curr->state[i+6])
        {
          if(curr->state[i]=='O')
          {
            return 1;// +1 to O because we found three O's in the column starting with index i.
          }
          else
          {
            return -1;// -1 to O because we found three X's in the column starting with index i.
          }
        }

      }

      // finished checking the rows and the columns
      // now we need to check the diagonals

      //diagonal one
      if(curr->state[0]!=' ' && curr->state[0]==curr->state[4] && curr->state[4]==curr->state[8])
      {
        if(curr->state[0] == 'O')
          return 1; // +1 to X because we found three X's in the principal diagonal
        else
          return -1; // -1 to X because we found three O's in the principal diagonal
      }

      //diagonal two
      if(curr->state[2]!=' ' && curr->state[2]==curr->state[4] && curr->state[4]== curr->state[6])
      {
        if(curr->state[2] == 'O')
          return 1; // +1 to O because we found three O's in the secondary diagonal
        else
          return -1;// -1 to O because we found three X's in the secondary diagonal
      }
    }
    // if the execution has come up to this pointer
    // it means we found no win-lose situation
    return 0;
    //hence is a draw situation
  }

}
