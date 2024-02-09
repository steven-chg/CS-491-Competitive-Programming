#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Rook, Bishop, and King
Little Petya is learning to play chess. He has already learned how to move a king, a rook and a bishop. 
Let us remind you the rules of moving chess pieces. A chessboard is 64 square fields organized into an 8 × 8 table. 
A field is represented by a pair of integers (r, c) — the number of the row and the number of the column 
(in a classical game the columns are traditionally indexed by letters). 
Each chess piece takes up exactly one field. To make a move is to move a chess piece, the pieces move by the following rules:
    1. A rook moves any number of fields horizontally or vertically.
    2. A bishop moves any number of fields diagonally.
    3. A king moves one field in any direction — horizontally, vertically or diagonally.

Petya is thinking about the following problem: what minimum number of moves is needed for each of these pieces to move from field (r1, c1) 
to field (r2, c2)? At that, we assume that there are no more pieces besides this one on the board. Help him solve this problem.

Input: The input contains four integers r1, c1, r2, c2 (1 ≤ r1, c1, r2, c2 ≤ 8) — the coordinates of the starting and the final field. 
The starting field doesn't coincide with the final one.

You can assume that the chessboard rows are numbered from top to bottom 1 through 8, and the columns are numbered from left to right 1 through 8.

Output: Print three space-separated integers: the minimum number of moves the rook, the bishop and the king (in this order) is 
needed to move from field (r1, c1) to field (r2, c2). If a piece cannot make such a move, print a 0 instead of the corresponding number.

*/

int main(){
    // retrieve the inputs 
    int startRow, startCol, endRow, endCol;
    scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);

    // sanity check, if start and end position is the same, return all 0s
    if(startRow == endRow && startCol == endCol){
        printf("%d %d %d", 0, 0, 0);
    }

    /* find the minimum number of moves by the rook
    - if the rook is already in the same row OR same column as the end position, then 1 move needed
    - if in different row AND different column, then 2 moves needed
    */
    int numMovesRook; 
    if(((startRow == endRow) && (startCol != endCol)) || ((startRow != endRow) && (startCol == endCol))){
        numMovesRook = 1;
    } else if(startRow != endRow && startCol != endCol){
        numMovesRook = 2;
    }

    // find the magnitude of row and column difference 
    int rowDiff = abs(startRow - endRow);
    int colDiff = abs(startCol - endCol);

    /* find the minimum number of moves by the bishop
    - if end position on the main diagonals of the start position, then 1 move needed (if magnitude of the row difference == magnitude of column difference)
    - if end position is NOT on the main diagonals of start position, and sum of row and col difference is even, then it can be reached in 2 moves
    - otherwise, it cannot be reached
    */
    int numMovesBishop;
    if(rowDiff == colDiff){
        numMovesBishop = 1;
    } else if((rowDiff + colDiff) % 2 == 0){
        numMovesBishop = 2;
    } else{
        numMovesBishop = 0;
    }

    /* find the minimum number of moves by the king
    - take the smaller number of (rowDiff, colDiff) (that is the number of diagonal steps we can take)
    then add that with the magnitude of difference between the two values (that is the remaining vertical or horizontal moves to take)
    - it also just equals the bigger number of (rowDiff, colDiff)
    */
    int numMovesKing;
    if(rowDiff <= colDiff){
        numMovesKing = rowDiff + abs(colDiff - rowDiff);
    } else{
        numMovesKing = colDiff + abs(rowDiff - colDiff);
    }

    // print number of moves
    printf("%d %d %d\n", numMovesRook, numMovesBishop, numMovesKing);

}