#include <bits/stdc++.h>

using namespace std;

// declare variable to track num of possible solutions 
int numSolutions = 0; 

/* Placing Queens
Count how many ways there are of placing 𝑘 queens on an 𝑛×𝑚 sized chessboard such that no two queens are attacking each other.
Two queens on the chessboard at location (𝑥1,𝑦1) and (𝑥2,𝑦2) attack each other if the are:
    on the same column or row, i.e. 𝑥1=𝑥2 or 𝑦1=𝑦2
    on the same diagonal, i.e. |𝑥1−𝑥2|=|𝑦1−𝑦2|

Input: The input consists of a single line with 𝑘, 𝑛, 𝑚. 1≤𝑘≤8 1≤𝑛≤8 1≤𝑚≤8

Output: Output on one line the number of ways to place 𝑘 queens on an 𝑛×𝑚 chessboard such that no two queens attack each other.
 */

// function to attempt to place queen in the current column
void solveNQueen(int col, int upDiagonal, int downDiagonal, int rows, int numQueensLeft, int numRows, int numCols){

    // if we have placed all queens, then increment number of solutions and return
    if(numQueensLeft == 0){
        numSolutions++;
        return;
    }

    // if current column we are trying to place queen is invalid, then return (col is 0 indexed)
    if(col >= numCols){
        return;
    }

    // otherwise, loop through all possible rows for each column and try to place a queen 
    for(int row = 0; row < numRows; row++){
        // set up curPos to check against upDiagonal, downDiagonal, and rows to see if you can place a queen at a specific row
        int curPos = (1 << row);

        // check if we can place queen in the current row (it is also possible that there are still enough columns to skip this current column)
        if(((curPos & upDiagonal) == 0) && ((curPos & downDiagonal) == 0) && ((curPos & rows) == 0)){
            // place queen at the current row; update upDiagonal, downDiagonal, and rows
            upDiagonal |= curPos;
            downDiagonal |= curPos; 
            rows |= curPos;

            // move on to the next column
            solveNQueen(col + 1, upDiagonal >> 1, downDiagonal << 1, rows, numQueensLeft - 1, numRows, numCols);    

            // backtrack by resetting the changes made to upDiagonal, downDiagonal, and rows
            upDiagonal &= ~curPos;
            downDiagonal &= ~curPos;
            rows &= ~curPos;

        }
    }

    // if there are still enough columns, we can skip this current column
    if ((numCols - col) > numQueensLeft){
        solveNQueen(col + 1, upDiagonal >> 1, downDiagonal << 1, rows, numQueensLeft, numRows, numCols);
    }
}

int main(){
    
    // Retrieve the inputs k, n, and m
    int numQueens, numRows, numCols;
    cin >> numQueens >> numRows >> numCols;

    /* DON"T NEED TO ACCOUNT FOR BEGINNING TO PLACE IN COLUMN 0 or 1 IF THERE ARE 6 COLUMNS AND 5 QUEENS TO PLACE; ACCOUNTED FOR IN solveNQueen FUNCTION*/
    // // loop through the possible starting column where we place our queen (if there are 6 columns and 5 queens to place, we can begin placing in column 0 or 1)
    // for(int columnStart = 0; columnStart < (numCols - numQueens + 1); columnStart++){
    //     // we are going to place the first queen, so the rows, upDiagonal, downDiagonal are 0 
    //     solveNQueen(columnStart, 0, 0, 0, numQueens, numRows, numCols);
    // }

    // simply start the NＱueen Calculation placing at column 0 
    solveNQueen(0, 0, 0, 0, numQueens, numRows, numCols);

    // print the number of solutions
    printf("%d\n", numSolutions);

    return 0;
}