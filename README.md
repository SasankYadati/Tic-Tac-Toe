# tic-tac-toe
Tic-Tac-Toe is a two player game, X and O, who take turns marking the spaces in a 3x3 grid. Each player takes turns, first X, and then O. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row first wins the game. The game always ends with a win-lose or a draw situation. 
<br>
Tic-Tac-Toe is an adversarial environment, which is a competitive environment where each player’s goal is to minimize the opponent’s score and hence maximize their own score. Also, the sum of the scores of all players is constant for every possible game (zero-sum game). 
<br>
We will define two players, MAX and MIN. They are named so, as they try to maximize and minimize the minimax value, respectively. We will implement two decision making algorithms, of which one makes completely random decisions and can be used as a standard to evaluate the other algorithm. Our primary focus is on the second algorithm i.e., the minimax algorithm to make decisions throughout the game. 
<br>
The main idea behind the algorithm is to calculate the minimax values of each possible state. The minimax value of a state is the utility for MAX of being in that state, assuming both players play optimally from there. 
<br>
In this project, we will show that minimax algorithm is better than the one that makes random moves. We will also show that minimax can only perform better in the case of non-optimal play of the opponent. We will conclude with the limitations of minimax algorithm and briefly talk about variations that have better performance.
