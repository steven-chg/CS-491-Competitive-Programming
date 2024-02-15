#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Biridian Forest
You're a mikemon breeder currently in the middle of your journey to become a mikemon master. 
Your current obstacle is go through the infamous Biridian Forest.

The forest
    The Biridian Forest is a two-dimensional grid consisting of r rows and c columns. 
    Each cell in Biridian Forest may contain a tree, or may be vacant. 
    A vacant cell may be occupied by zero or more mikemon breeders (there may also be breeders other than you in the forest). 
    Mikemon breeders (including you) cannot enter cells with trees. One of the cells is designated as the exit cell.
    The initial grid, including your initial position, the exit cell, and the initial positions of all other breeders, 
    will be given to you. Here's an example of such grid (from the first example):

Moves 
    Breeders (including you) may move in the forest. In a single move, breeders may perform one of the following actions:
        Do nothing.
        Move from the current cell to one of the four adjacent cells (two cells are adjacent if they share a side). 
        Note that breeders cannot enter cells with trees.
        If you are located on the exit cell, you may leave the forest. Only you can perform this move — all other mikemon breeders will 
        never leave the forest by using this type of movement.
    After each time you make a single move, each of the other breeders simultaneously make a single move 
    (the choice of which move to make may be different for each of the breeders).

Mikemon battle
    If you and t (t > 0) mikemon breeders are located on the same cell, exactly t mikemon battles will ensue that time 
    (since you will be battling each of those t breeders once). 
    After the battle, all of those t breeders will leave the forest to heal their respective mikemons.
    Note that the moment you leave the forest, no more mikemon battles can ensue, even if another mikemon breeder move to the exit cell 
    immediately after that. Also note that a battle only happens between you and another breeders — 
    there will be no battle between two other breeders (there may be multiple breeders coexisting in a single cell).

Your goal
    You would like to leave the forest. In order to do so, you have to make a sequence of moves, ending with a move of the final type. 
    Before you make any move, however, you post this sequence on your personal virtual idol Blog. Then, you will follow this sequence of 
    moves faithfully.

Goal of other breeders
    Because you post the sequence in your Blog, the other breeders will all know your exact sequence of moves even before you make your first move. 
    All of them will move in such way that will guarantee a mikemon battle with you, if possible. The breeders that couldn't battle you will do 
    nothing.

Your task
    Print the minimum number of mikemon battles that you must participate in, assuming that you pick the sequence of moves that minimize this number. 
    Note that you are not required to minimize the number of moves you make.

Input: The first line consists of two integers: r and c (1 ≤ r, c ≤ 1000), denoting the number of rows and the number of columns in Biridian Forest. 
The next r rows will each depict a row of the map, where each character represents the content of a single cell:
    'T': A cell occupied by a tree.
    'S': An empty cell, and your starting position. There will be exactly one occurence of this in the map.
    'E': An empty cell, and where the exit is located. There will be exactly one occurence of this in the map.
    A digit (0-9): A cell represented by a digit X means that the cell is empty and is occupied by X breeders (in particular, if X is zero, 
    it means that the cell is not occupied by any breeder).
It is guaranteed that it will be possible for you to go from your starting position to the exit cell through a sequence of moves.

Output: A single line denoted the minimum possible number of mikemon battles that you have to participate in if you pick a strategy that 
minimize this number.
*/

int main(){
    /* Notes
    - find the shortest distance/path from your breeder to the exit
    - find the shortest distance/path from each breeder to the exit
    - compare the shortest paths; if their shortest path is less than or equal to yours, increment the number of battles
    */

    // retrieve the row and column of the forest
    ll numRow, numCol;
    cin >> numRow >> numCol;

    // declare a 2D vector to represent the forest (with number of rows = numRow); 0 indexed
    vector< vector<char> > forest(numRow);

    // declare a 2D vector to store the distances each cell is from the exit (with number of rows = numRow); 0 indexed
    vector< vector<ll> > distance(numRow);

    // declare a queue that we will use to perform BFS
    queue< pair<ll, ll> > bfsOrder;

    // loop to set up the forest and distance 2D vectors and insert first cell into the bfs queue
    for(ll row = 0; row < numRow; row++){
        string currentRow;
        cin >> currentRow;
        for(ll col = 0; col < numCol; col++){
            forest[row].push_back(currentRow[col]);
            // if the current cell is the exit, form it as the starting pair at insert it into the queue (also set distance to 0)
            if(currentRow[col] == 'E'){
                bfsOrder.push(make_pair(row, col));
                distance[row].push_back(0);
            } else{
                // if current cell isn't the exit, then initialize its distance to the exit to be a very large value 
                distance[row].push_back(1e6);
            }
        }
    }

    /* at this point, the forest 2D vector is set up to the forest initial condition; distance 2D vector has every cell initialized to a large value, except Exit cell distance set to 0 */

    // declare variable to store distance from Exit to Start position of your breeder
    ll breederDistance;

    // perform bfs to traverse the entire 2D forest
    while(!bfsOrder.empty()){
        ll row = bfsOrder.front().first;
        ll col = bfsOrder.front().second;
        bfsOrder.pop();
        // for each cell, attempt to move to adjacent cells
        for(int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    // attempt to move left
                    if(col <= 0) break;
                    if(distance[row][col - 1] == 1e6 && forest[row][col - 1] != 'T'){
                        distance[row][col - 1] = distance[row][col] + 1;
                        bfsOrder.push(make_pair(row, col - 1));
                    }

                    if(forest[row][col - 1] == 'S') breederDistance = distance[row][col - 1];

                case 1:
                    // attempt to move right
                    if(col >= numCol - 1) break;
                    if(distance[row][col + 1] == 1e6 && forest[row][col + 1] != 'T'){
                        distance[row][col + 1] = distance[row][col] + 1;
                        bfsOrder.push(make_pair(row, col + 1));
                    }

                    if(forest[row][col + 1] == 'S') breederDistance = distance[row][col + 1];

                case 2:
                    // attempt to move up
                    if(row <= 0) break;
                    if(distance[row - 1][col] == 1e6 && forest[row - 1][col] != 'T'){
                        distance[row - 1][col] = distance[row][col] + 1;
                        bfsOrder.push(make_pair(row - 1, col));
                    }

                    if(forest[row - 1][col] == 'S') breederDistance = distance[row - 1][col];

                case 3:
                    // attempt to move down
                    if(row >= numRow - 1) break;
                    if(distance[row + 1][col] == 1e6 && forest[row + 1][col] != 'T'){
                        distance[row + 1][col] = distance[row][col] + 1;
                        bfsOrder.push(make_pair(row + 1, col));
                    }  

                    if(forest[row + 1][col] == 'S') breederDistance = distance[row + 1][col];

            }
        }
    }

    /* at this point, every cell in the forest has been marked by its distance from the Exit (excluding cells with trees) */

    // loop through the entire forest and track how many times there is a cell with other breeders that has distance to exit less than or equal to your breeder's distance to exit
    ll numBattles = 0;
    for(ll rowNum = 0; rowNum < numRow; rowNum++){
        for(ll colNum = 0; colNum < numCol; colNum++){
            if((forest[rowNum][colNum] - '0') >= 0 && (forest[rowNum][colNum] - '0') <= 9 && distance[rowNum][colNum] <= breederDistance){
                numBattles += forest[rowNum][colNum] - '0';
            }
        }
    }

    cout << numBattles << endl;


    
}
