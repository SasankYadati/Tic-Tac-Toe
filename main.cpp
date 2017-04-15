#include<iostream>
#include"node.h"
#include"game.h"
#include"random.h"
#include"minimax.h"

using namespace std;

void display(Node* curr);
void choose_mark(char *user, char *bot);
void choose_bot_type(int *bot_type);
void play_game(Node *initial,char user,char bot,int bot_type,int *utility_user,int *utility_bot);


int main()
{
  char user,bot; // to indicate respective player marks.

  int bot_type; // 1 for random move maker and 2 for minimax strategist.

  int utility_user,utility_bot; // utilities for the user and the bot respectively.

  // Welcome the user!
  cout<<endl<<"Welcome to Tic-Tac-Toe!"<<endl;

  // create the initial node corresponding to the initial state of the game.
  Node* initial;
  initial = new Node;

  //cout<<"SIZE OF NODE "<<sizeof(Node)<<endl;

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
  Node *test;

  test = new Node;

  for(int i=0; i<6; i++)
  {
    if(i%2==0)test->state[i] = 'X';
    else test->state[i] = 'O';
  }
  //display(RESULT(test,6));
  int decision = MINIMAX_DECISION(*test);
  cout<<"Decision is "<<decision<<endl;

  #endif
  // call the play_game function
  play_game(initial,user,bot,bot_type,&utility_user,&utility_bot);
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

void play_game(Node *initial,char user,char bot,int bot_type,int *utility_user,int *utility_bot)
{
  // initialize the utilities of the players to zero
  *utility_user = 0;
  *utility_bot = 0;

  //declare varibales to hold actions
  int action_user,action_bot;

  Node * curr = initial;
  Node next;

  //check the type of the bot the user wants to play against
  if(bot_type==1) // the random move maker
  {
    //check who goes first
    if(user=='X')
    {

      do {

        do {
          cout<<endl<<"Choose your square to mark!"<<endl;
          display(curr);
          cin>>action_user;
        } while(curr->state[action_user]!=' ');

        curr = RESULT(curr,action_user);
        display(curr);
        cout<<endl;

        if(TERMINAL_TEST(curr))
        {
          cout<<"Utility for user: "<<UTILITY(curr,user)<<endl;
          cout<<"Utility for bot: "<<UTILITY(curr,bot)<<endl;
          return;
        }

        cout<<"Mr. Random Move Maker is calculating his move!"<<endl;
        action_bot = RANDOM_DECISION(curr);
        curr = RESULT(curr,action_bot);
        display(curr);
        cout<<endl;

        if(TERMINAL_TEST(curr))
        {
          cout<<"Utiliy for user : "<<UTILITY(curr,user)<<endl;
          cout<<"Utility for bot: "<<UTILITY(curr,bot)<<endl;
          return;
        }
      }while(true);
    }
    else // user is O and the bot is X
    {
      do {
          cout<<"Mr. Random Move Maker is calculating his move!"<<endl;
          action_bot = RANDOM_DECISION(curr);

          curr = RESULT(curr,action_bot);
          display(curr);
          cout<<endl;
          if(TERMINAL_TEST(curr)==true)
          {
            cout<<"Utility for user: "<<UTILITY(curr,user)<<endl;
            cout<<"Utility for bot: "<<UTILITY(curr,bot)<<endl;
            return;
          }
        do {
          cout<<endl<<"Choose your square to mark!"<<endl;
          display(curr);
          cin>>action_user;
        } while(curr->state[action_user]!=' ');

        curr = RESULT(curr,action_user);
        display(curr);
        cout<<endl;
        if(TERMINAL_TEST(curr)==true)
        {
          cout<<"Utility for user: "<<UTILITY(curr,user)<<endl;
          cout<<"Utility for bot: "<<UTILITY(curr,bot)<<endl;
          return;
        }


      } while(true);
    }
  }
  else // the minimax strategist
  {
    //check who goes first
    if(user=='X')
    {
      do {

        do {
          cout<<endl<<"Choose your square to mark!"<<endl;
          display(curr);
          cin>>action_user;
        } while(curr->state[action_user]!=' ');

        curr = RESULT(curr,action_user);

        display(curr);
        cout<<endl;

        if(TERMINAL_TEST(curr)==true)
          return;

        cout<<"The Minimax Strategist is calculating his move!"<<endl;
        action_bot = MINIMAX_DECISION(*curr);
        curr = RESULT(curr,action_bot);

        display(curr);

        if(TERMINAL_TEST(curr)==true)
          return;
        cout<<endl;

      } while(true);

    }
    else // user is O and the bot is X
    {
      do {
          cout<<"The Minimax Strategist is calculating his move!"<<endl;

          action_bot = MINIMAX_DECISION(*curr);
          curr = RESULT(curr,action_bot);

          display(curr);
          cout<<endl;

          if(TERMINAL_TEST(curr)==true)
            return;

        do {
          cout<<endl<<"Choose your square to mark!"<<endl;
          display(curr);
          cin>>action_user;
        } while(curr->state[action_user]!=' ');

        curr = RESULT(curr,action_user);

        display(curr);
        cout<<endl;

        if(TERMINAL_TEST(curr)==true)
          return;


      } while(true);

    }

  }
}
