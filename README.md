# Tic Tac Toe
Tic Tac Toe Game, coded entirely in C++, uses the console output to print the game board.

## Development
This uses a two-dimensional char array with three rows and columns as the game board. Player 1 and Player 2 takes turns to play the game. The program does the following:
```C++
// Function prototypes to understand the game logic.
void display(); // Displays the contents of the 2-D board array. Uses iomanip to format the output.
bool isLegalMove(int row, int col); // checks for empty path and valid row and col index.
```
Each element of the array is intialized with an *asterik*.
Allows Player 1 and Player 2, respectively, to select a location on the board for an X or an O. Program asks the user to enter the row and column numbers.

Winner: Player wins when there are 3 (X's or O's) in a row, in a column, or diagonally across the board.

Tie: Occurs when all the locations in the board are full, but there is no winner.
