# Tic-Tac-Toe
author : happystick<br>
mail-id : sasankyadati@gmail.com<br>
last mod. :27/03/2017<br>

# Introduction
Tic-Tac-Toe is a two player game, X and O, who take turns marking the spaces in a 3x3 grid. Each player takes turns, first X, and then O. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row first wins the game. The game always ends with a win-lose or a draw situation. 
<br>

# Game play
Each player takes turns, first X, and then O. The goal is to get three in a row in a 3x3 board. Each player on their turn can mark only an empty cell with their corresponding mark (X or O). The game ends with a win-lose or a draw situation.
<br>

# Game in Numbers
So, how many Tic-Tac-Toe games are possible? This is a simple question solvable with a little brute force and basic combinatory techniques. It is quite obvious that the answer is towards the south of 9!. Total number of possible games is equal to the sum of the number of games that end on the 5th move, 6th move, 7th move, 8th move and the 9th move. A brief calculation of this sum results in 255,168. These calculations do not take symmetry of the board into consideration. It is also interesting to note that most games end in a draw (always, if both players play optimally).
<br>

# Game Environment
Tic-Tac-Toe is an adversarial environment. Adversarial environment refers to a competitive environment where each player’s goal is to minimize the opponent’s score and thereby maximize their own score. 
<br>
Hence, this game belongs to a class of adversarial search problems where our aim is to find a way (solution) to maximize our score in the presence of an adversary who is planning against us. In particular, Tic-Tac-Toe is a two player environment. It follows turn taking which means actions of a player are taken one followed by the other. Moreover, this game is a zero sum game, meaning, the sum of the utilities (scores) of the players at the end of the game is constant for every game.
<br>

# Let's Formally Define The Game!
We define the game to be a formal search problem with the following elements.
<br>
<h4> •	S0 </h4>
<br>
The initial state, which specifies how the game is setup at start.In Tic-Tac-Toe, this represents a 3x3 board with all the cells empty.
<br>

<b> •	PLAYER ( s ) </b>
<br>
Defines which player has the move in the given state s.
<br>

<b> •	ACTIONS ( s ) </b>
<br>
Returns the set of legal moves in the state s.
<br>

<b>•	RESULT ( s , a ) </b>
<br>
Also known as the transitional model, returns the resulting state s’ on selecting move a in the state s.
<br>

<b> •	TERMINAL-TEST ( s ) </b>
<br>
Returns true, when the game is over and false otherwise.
<br>

<b> •	UTILITY ( s , p ) </b>
<br>
Returns the utility / score of player p in the terminal state s.   In Tic-Tac-Toe, the possible utility values are +1/2 (draw), +1 (win) and -1 (lose).
<br>
# Game Tree
The initial state, ACTIONS(s) and RESULT(s,a) together define the game tree with the initial state as the root of the tree. We use the term search tree to describe a tree that is superimposed on the game tree and examines enough nodes to determine what move to make. Following figure shows a partial game tree.
<br>
<img src = './game-tree.jpg'></img>
<br>
