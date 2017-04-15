#ifndef GAME_H
#define GAME_H

Node* RESULT(Node* curr, int action); // returns a pointer to the resulting node from the given action
bool TERMINAL_TEST(Node* curr); // returns true if the state is a terminal state, false otherwise.
int UTILITY(Node* curr, char player='X'); // returns the utility for 'player' in the corresponding state.
char PLAYER(Node* curr); //return an 'X' or an 'O'
int* ACTIONS(Node* curr); //returns an array indicating all the possible actions

#endif
