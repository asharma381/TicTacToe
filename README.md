# Tic Tac Toe
Tic Tac Toe Game, coded entirely in C++, uses the console output to print the game board.

## Development
This uses a two-dimensional char array with three rows and columns as the game board. Player 1 and Player 2 takes turns to play the game. The program does the following:
```C++
// Function prototypes to understand the game logic.
void display(); // Displays the contents of the 2-D board array. Uses iomanip to format the output.
bool isLegalMove(int row, int col); // checks to make sure user enters appropriate position and the position is empty.
```
