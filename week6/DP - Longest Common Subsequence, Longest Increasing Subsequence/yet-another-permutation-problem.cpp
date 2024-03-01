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

/* RECURSIVE APPROACH: TIME LIMIT EXCEEDED */
// recursive function to find the longest common subsequence length
int LCS(ll i, ll j, const vector<ll>& arrayOne, const vector<ll>& arrayTwo) {
    // base case; if either of the indices reaches the end of the array, return 0
    if (i == arrayOne.size() || j == arrayTwo.size())
        return 0;

    // if current elements are equal, return 1 + recursive return of the next elements
    if (arrayOne[i] == arrayTwo[j]){
        return 1 + LCS(i + 1, j + 1, arrayOne, arrayTwo);
    } 
     
    // else, check for the longest common subsequence; 2 possibilities
    // 1) exclude current element from arrayOne 2) exclude current element from arrayTwo 
    return max(LCS(i + 1, j, arrayOne, arrayTwo), LCS(i, j + 1, arrayOne, arrayTwo));
}

int main(){
    ll numCases;
    cin >> numCases;

    /* Notes:
    - find the longest common subsequence length 
    - then the answer will simply be 2*(length of each array - length of longest common subsequence) 
    */

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll arrayLength;
        cin >> arrayLength;
        
        vector<ll> arrayOne(arrayLength);
        vector<ll> arrayTwo(arrayLength);

        // retrieve the two arrays 
        for(int i = 0; i < 2; i++){
            for(int index = 0; index < arrayLength; index++){
                if(i == 0) cin >> arrayOne[index];
                else cin >> arrayTwo[index];
            }
        } 

        // recursively find the longest common subsequence length
        ll maxLength = LCS(0, 0, arrayOne, arrayTwo);
        ll turnsNeeded = 2*(arrayLength - maxLength);
        cout << turnsNeeded << endl;
    }
}

/* DP MEMOIZATION (2 ROWS): TIME LIMIT EXCEEDED */
// int main(){
//     ll numCases;
//     cin >> numCases;

//     /* Notes:
//     - find the longest common subsequence length 
//     - then the answer will simply be 2*(length of each array - length of longest common subsequence) 
//     */

//     for(int caseNum = 0; caseNum < numCases; caseNum++){
//         ll arrayLength;
//         cin >> arrayLength;
        
//         vector<ll> arrayOne(arrayLength);
//         vector<ll> arrayTwo(arrayLength);

//         // instead of forming the entire 2D matrix, just keep track of 2 rows at a time and alternate
//         vector<ll> rowOne(arrayLength+1);
//         vector<ll> rowTwo(arrayLength+1);

//         // retrieve the two arrays 
//         for(int i = 0; i < 2; i++){
//             for(int index = 0; index < arrayLength; index++){
//                 if(i == 0) cin >> arrayOne[index];
//                 else cin >> arrayTwo[index];
//             }
//         } 

//         // set the first row and first column of the dp array to 0
//         for(int i = 0; i <= arrayLength; i++){
//             rowOne[i] = 0;
//         }

//         // loop through both arrays and fill in the dp array row by row 
//         for(int i = 1; i <= arrayLength; i++){
//             for(int j = 1; j <= arrayLength; j++){
//                 // treat rowTwo as current row and rowOne as previous row
//                 if(arrayOne[i-1] != arrayTwo[j-1]){
//                     rowTwo[j] = max(rowTwo[j-1], rowOne[j]); 
//                 } else{
//                     rowTwo[j] = 1 + rowOne[j-1];
//                 }
//             }
//             swap(rowOne, rowTwo);
//         }

//         // calculate number of turns needed
//         ll longestCommonSubsequenceLength = rowOne[arrayLength];
//         ll turnsNeeded = 2*(arrayLength - longestCommonSubsequenceLength);
//         cout << turnsNeeded << endl;
//     }
// }

/* DP MEMOIZATION (FULL MATRIX): MEMORY EXCEEDED LIMIT */
// int main(){
//     ll numCases;
//     cin >> numCases;

//     /* Notes:
//     - find the longest common subsequence length 
//     - then the answer will simply be 2*(length of each array - length of longest common subsequence) 
//     */

//     for(int caseNum = 0; caseNum < numCases; caseNum++){
//         ll arrayLength;
//         cin >> arrayLength;
        
//         vector<ll> arrayOne(arrayLength);
//         vector<ll> arrayTwo(arrayLength);
//         ll dp[arrayLength+1][arrayLength+1];

//         // retrieve the two arrays 
//         for(int i = 0; i < 2; i++){
//             for(int index = 0; index < arrayLength; index++){
//                 if(i == 0) cin >> arrayOne[index];
//                 else cin >> arrayTwo[index];
//             }
//         } 

//         // set the first row and first column of the dp array to 0
//         for(int i = 0; i <= arrayLength; i++){
//             dp[i][0] = 0;
//             dp[0][i] = 0;
//         }

//         // loop through both arrays and fill in the dp array row by row 
//         for(int i = 1; i <= arrayLength; i++){
//             for(int j = 1; j <= arrayLength; j++){
//                 if(arrayOne[i-1] != arrayTwo[j-1]){
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 } else{
//                     dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], 1 + dp[i-1][j-1]));  // pretty much simply 1+dp[i-1][j-1]
//                 }
//             }
//         }

//         // calculate number of turns needed
//         ll longestCommonSubsequenceLength = dp[arrayLength][arrayLength];
//         ll turnsNeeded = 2*(arrayLength - longestCommonSubsequenceLength);
//         cout << turnsNeeded << endl;
//     }
// }