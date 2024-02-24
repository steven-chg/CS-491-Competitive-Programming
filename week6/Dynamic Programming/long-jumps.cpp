#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Long Jumps
Polycarp found under the Christmas tree an array 𝑎 of 𝑛 elements and instructions for playing with it:
    At first, choose index 𝑖 (1≤𝑖≤𝑛) — starting position in the array. Put the chip at the index 𝑖 (on the value 𝑎𝑖).
    While 𝑖≤𝑛, add 𝑎𝑖 to your score and move the chip 𝑎𝑖 positions to the right (i.e. replace 𝑖 with 𝑖+𝑎𝑖).
    If 𝑖>𝑛, then Polycarp ends the game.

For example, if 𝑛=5 and 𝑎=[7,3,1,2,3], then the following game options are possible:
    Polycarp chooses 𝑖=1. Game process: 𝑖=1⟶8 (+7). The score of the game is: 𝑎1=7.
    Polycarp chooses 𝑖=2. Game process: 𝑖=2⟶5 (+3) ⟶8 (+3). The score of the game is: 𝑎2+𝑎5=6.
    Polycarp chooses 𝑖=3. Game process: 𝑖=3⟶4 (+1) ⟶6 (+2). The score of the game is: 𝑎3+𝑎4=3.
    Polycarp chooses 𝑖=4. Game process: 𝑖=4⟶6 (+2). The score of the game is: 𝑎4=2.
    Polycarp chooses 𝑖=5. Game process: 𝑖=5⟶8 (+3). The score of the game is: 𝑎5=3.

Help Polycarp to find out the maximum score he can get if he chooses the starting index in an optimal way.

Input: The first line contains one integer 𝑡 (1≤𝑡≤10^4) — the number of test cases. Then 𝑡 test cases follow.

The first line of each test case contains one integer 𝑛 (1≤𝑛≤2⋅10^5) — the length of the array 𝑎.

The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10^9) — elements of the array 𝑎.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅10^5.

Output: For each test case, output on a separate line one number — the maximum score that Polycarp can get by playing 
the game on the corresponding array according to the instruction from the statement. 
Note that Polycarp chooses any starting position from 1 to 𝑛 in such a way as to maximize his result.
*/

int main(){
    ll numCases;
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll arrayLength;
        cin >> arrayLength;

        vector<ll> array(arrayLength+1, 0);
        for(int index = 1; index <= arrayLength; index++){
            cin >> array[index];
        }

        // work backwards from the end of the array to find total score starting from each index
        ll maxScore = 0;
        for(int index = arrayLength; index > 0; index--){
            if((index + array[index]) <= arrayLength) array[index] += array[index+array[index]];
            if(array[index] > maxScore) maxScore = array[index]; 
        }

        // // now, traverse the entire array and find maximum possible score 
        // ll maxScore = 0;
        // for(int i = 1; i <= arrayLength; i++){
        //     if(array[i] > maxScore) maxScore = array[i];
        // }

        cout << maxScore << endl;
    }
}