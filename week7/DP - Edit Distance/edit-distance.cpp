#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Edit Distance
Compute the edit distance between two strings.

The edit distance of a string 𝑠 and a string 𝑡 is the minimum number of operations you need to perform to 𝑠 to get 𝑡.

The following are the valid operations:
    INSERT 𝑝𝑜𝑠,𝑐ℎ – insert the letter 𝑐ℎ in the string at position 𝑝𝑜𝑠. The letter 𝑐ℎ becomes the 𝑝𝑜𝑠th symbol of the string, 
    and all letters to the right shift right by 1.
    DELETE 𝑝𝑜𝑠 – delete the letter 𝑐ℎ in the string at position 𝑝𝑜𝑠. The letters to the right shift left by one.
    REPLACE 𝑝𝑜𝑠,𝑐ℎ – replace the 𝑝𝑜𝑠th letter in the string by 𝑐ℎ.

Input: The first line contains 𝑠, the second line contains 𝑡. The lines consist only of capital Latin letters, 
their lengths are positive numbers from 1 to 1000.

Output: Output the minimum edit distance between 𝑠 and 𝑡.
*/

// 2D array of max size 1001 x 1001 (since maximum length of each string is 1000) to store min. edit distance for every possible substring
ll dp[1001][1001];

int main(){
    string first, second;
    cin >> first;
    cin >> second;

    ll cost;

    // initialize the first row (to its column value) and first column (to its row value) cells 
    for(int i = 0; i <= first.length(); ++i) dp[i][0]= i;
    for(int j = 0; j <= second.length(); ++j) dp[0][j]= j;
    
    // loop through the entire length of both strings
    for(int i = 1; i <= first.length(); ++i){
        for(int j = 1; j <= second.length(); ++j) { 
            // check if the two characters are the same, if so, then cost = 0; else, cost = 1
            cost = first[i-1] == second[j-1] ? 0 :1;
            // find the minimum edit distance for this substring 1) delete char from first, 2) delete char from second, 3) delete char from both (no cost if they're the same)
            dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + cost));
        }
    }
    // print minimum edit distance for the entire string 
    cout << dp[first.length()][second.length()] << endl;
}