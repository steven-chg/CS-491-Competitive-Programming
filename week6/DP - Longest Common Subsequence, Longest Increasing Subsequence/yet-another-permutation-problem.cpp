#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Yet Another Permutation Problem
Amir and Akbar have got two arrays, each consisting a permutation of 1 to 𝑛, 
They want to play a game, the goal of the game is making the arrays similar, two arrays are similar if they have same length and all 
of the elements in each index of both arrays are equal.

In each turn one can remove a single integer from his array, 
If both play optimally, find out the minimum number of turns it takes to finish the game.

Input: The first line of input shows the number of test cases 𝑡, Each test case will contain 3 lines. 
The first line contains a single integer 𝑛, The length of each array. 1≤𝑛≤10^5.

Second and third line each will contain 𝑛 space separated integers indicating the numbers in permutations 𝐴 and 𝐵 respectively.

It's guaranteed that sum of 𝑛 overall testcases will not exceed 10^5.

Output: For each test case, print a single integer in a line, the minimum number of turns to finish the game.
*/

int main(){
    ll numCases;
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll arrayLength;
        cin >> arrayLength;
        
        vector<ll> arrayOne;
        vector<ll> arrayTwo;
        for(int i = 0; i < 2; i++){
            for(int index = 0; index < arrayLength; index++){
                if(i == 0) cin >> arrayOne[index];
                else cin >> arrayTwo[index];
            }
        } 
    }
}