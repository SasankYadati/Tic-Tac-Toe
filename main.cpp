#include<iostream>
#include"node.h"
#include"game.h"
#include"minimax.h"
#include"random.h"

using namespace std;

void display(Node* curr);
void choose_mark(char *user, char *bot);
void choose_bot_type(int *bot_type);

int main()
{
  char user,bot; // to indicate respective player marks.
  char max,min; // assign the players to max and min. Remember that max moves first, always.

  int bot_type; // 1 for random move maker and 2 for minimax strategist.

  int chosen_action_user,chosen_action_bot; // to store the actions taken by the user and the bot respectively.

  // Welcome the user!
  cout<<endl<<"Welcome to Tic-Tac-Toe!"<<endl;

  // create the initial node corresponding to the initial state of the game.
  Node* initial;
  initial = new Node;

  //display the board initially.
  display(initial);

  //ask the user to choose the bot type
  choose_bot_type(&bot_type);

  //display the chosen type of the bot
  if(bot_type==1)
  {
    cout<<"You are playing against The Random Move Maker!"<<endl;

  }
  else
  {
    cout<<"You are playing against The Minimax Strategist!"<<endl;
  }
  cout<<"Good Luck!"<<endl;
  

  // ask the user to choose his mark and assign appropriate mark to the user.
  choose_mark(&user,&bot);



  #if 0
  cout<<user<<endl;
  cout<<bot<<endl;
  #endif




  // if the user is O, the bot will move first.
  // max is bot. min is user.



  // if the user is O, make the bot move first.

  return 0;
}

void display(Node* curr)
{
  // given a node, displays the corresponding state (board) of the node.
  for(int i=0; i<9; ++i)
  {
    if(i%3 == 0 && i>2)
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
  cout<<endl<<endl<<endl;
}

void choose_mark(char *user, char *bot)
{
  // ask the user to decide on his mark(X or O).
  do {
    cout<<"X goes first!"<<endl<<endl;
    cout<<"Choose your mark! (X or O)"<<endl<<endl;
    cin>>(*user);
  } while(*user!='X' && *user!='O' );

  // assign the appropriate mark to the bot.
  if(*user=='X')
  {
    *bot='O';
  }
  else
  {
    *bot='X';
  }
}

void choose_bot_type(int *bot_type)
{
  // ask the user to choose the type of bot
  // 1 for random move Maker
  // 2 for the minimax strategist
  do {
    cout<<"Choose the type of the bot!"<<endl;
    cout<<"1. Random Move Maker!"<<endl;
    cout<<"2. The Minimax Strategist"<<endl<<endl<<endl;
    cin>>(*bot_type);
  } while(*bot_type!=1 && *bot_type!=2);

}
