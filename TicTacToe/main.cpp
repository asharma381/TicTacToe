//
//  main.cpp
//  TicTacToe
//
//  Created by Aditya Sharma on 6/21/20.
//  Copyright © 2020 Aditya Sharma. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;
const int ROWS = 3;
const int COLS = 3;

void display();
bool didPlayerWin();
bool isTie();
bool isLegalMove(int, int);
void makeMove(int, int, char);
char board[][COLS] = {{'*','*','*'},
                  {'*','*','*'},
                  {'*','*','*'}};

int main() {
    display();
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
    
    if(isTie()){
        cout << endl << "Tie Game!" << endl;
        return 0;
    }
    
    if(isPlayer1) cout << endl << "Player #2 Wins!" << endl;
    else cout << endl << "Player #1 Wins!" << endl;
    
    return 0;
}

void display(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}

void makeMove(int r, int c, char p){
    board[r][c] = p;
    display();
}

bool isLegalMove(int row, int col){
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        return false;
    }
    if(board[row][col] != '*'){
        return false;
    }
    return true;
}

bool checkRows(char c){
    bool didPlayerWin = false;
    for(int row = 0; row < 3; row++){
        int arr[3];
        for(int i = 0; i < 3; i++){
            arr[i] = board[row][i];
        }
        bool isRowCorrect = true;
        for(int i = 0; i < 3; i++){
            if(arr[i] != c){
                isRowCorrect = false;
            }
        }
        if(isRowCorrect){
            didPlayerWin = true;
        }
    }
    return didPlayerWin;
}

bool checkCols(char c) {
    bool didPlayerWin = false;
    
    for(int col = 0; col < 3; col++){
        int arr[3];
        for(int i = 0; i < 3; i++){
            arr[i] = board[i][col];
        }
        bool isColCorrect = true;
        for(int i = 0; i < 3; i++){
            if(arr[i] != c){
                isColCorrect = false;
            }
        }
        if(isColCorrect){
            didPlayerWin = true;
        }
    }
    return didPlayerWin;
}

bool checkDiag(char c){
    int arr[3];
    bool didPlayerWin = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                arr[i] = board[i][j];
            }
        }
    }
    
    bool isRDiag = true;
    for(int i = 0; i < 3; i++){
        if(arr[i] != c){
            isRDiag = false;
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == (2-j)){
                arr[i]= board[i][j];
            }
        }
    }
    
    bool isLDiag = true;
        for(int i = 0; i < 3; i++){
            if(arr[i] != c){
                isLDiag = false;
            }
        }
    if(isLDiag || isRDiag){
        didPlayerWin = true;
    }
    return didPlayerWin;
}

bool didPlayerWin(){
    bool player1Win =  checkDiag('X') || checkCols('X') || checkRows('X');
    bool player2Win = checkDiag('O') || checkCols('O') || checkRows('O');
    return player1Win || player2Win;
}

bool isTie(){
    bool tie = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '*'){
                tie = false;
            }
        }
    }
    return tie;
}
