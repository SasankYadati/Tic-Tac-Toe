#include<iostream>
#include"node.h"
#include"game.h"
#include"minimax.h"
#include"random.h"

void display( Node* curr_node);

int main()
{
  char user,bot; // to indicate respective player marks.

  cout<<"Welcome to Tic-Tac-Toe!"<<endl;

  // scan and validate user's input mark.
  Node* initial;
  initial = new Node;

  display(initial);


  do {

    cout<<"X goes first!"<<endl;
    cout<<"Choose your mark! (X or O)"<<endl;
    cin>>user;

  } while(user!='X' && user!='O');

  // assign appropriate mark to the bot.
  if(user=='X')
  {
    bot='O';
  }
  else
  {
    bot='X';
  }



  return 0;
}

void display( Node* curr_node)
{
  for(int i=0; i<9; ++i)
  {
    if(i%3 == 0)
    {
      cout<<endl;
      cout<<"---------"<<endl;
    }

    cout<<curr->state[i];

    if(i%3 != 2)
    {
      cout<<" | ";
    }

  }
}
