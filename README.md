# Tic Tac Toe
Tic Tac Toe Game, coded entirely in C++, uses the console output to print the game board.

## Development
This uses a two-dimensional char array with three rows and columns as the game board. Player 1 and Player 2 takes turns to play the game. The program does the following:
```C++
// Function prototypes to understand the game logic.
void display(); // Displays the contents of the 2-D board array. Uses iomanip to format the output.
bool isLegalMove(int row, int col); // checks for empty path and valid row and col index.
void makeMove(int row, int col, char symbol); // given row, column, and player symbol 'X' or 'O'.
bool checkRows(char symbol); //checks each row. True: 3 in a row.
bool checkCols(char symbol); //checks each column.
bool checkDiag(char symbol); // checks the right and left diagonal.
bool isTie(); //checks to see if board is full
```
Each element of the array is intialized with an *asterik*. Game allows Player 1 and Player 2, respectively, to select a location on the board for an X or an O. Program asks the user to enter the row and column numbers.

Winner: Player wins when there are 3 (X's or O's) in a row, in a column, or diagonally across the board.

Tie: Occurs when all the locations in the board are full, but there is no winner.

## Game Logic
```C++
    bool isPlayer1 = true;
    while(!didPlayerWin() && !isTie()){
        int row, col;
        do{
            if(isPlayer1){
                cout << "\nPlayer #1" << endl;
                cout << "Select a location on \nthe board for an X." << endl;
            }else{
                cout << "\nPlayer #2" << endl;
                cout << "Select a location on \nthe board for an O." << endl;
            }
            cout << "Enter row and column:";
            cin >> row >> col;
        }while(!isLegalMove(row, col));
        if(isPlayer1){
            makeMove(row, col, 'X');
            isPlayer1 = false;
        }else{
            makeMove(row, col, 'O');
            isPlayer1 = true;
        }
    }
```
## Usage
You can play this free TicTacToe Game. like you would any other header library by downloading it and copying it to a directory on your include path. Elevate is written for C++11 and above. COMING SOON: Use elevate on systems that don't have it by including it in your source files.
