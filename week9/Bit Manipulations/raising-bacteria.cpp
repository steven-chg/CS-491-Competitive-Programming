#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Raising Bacteria
You are a lover of bacteria. You want to raise some bacteria in a box.

Initially, the box is empty. 
Each morning, you can put any number of bacteria into the box. And each night, every bacterium in the box will split into two bacteria. 
You hope to see exactly x bacteria in the box at some moment.

What is the minimum number of bacteria you need to put into the box across those days?

Input: The only line containing one integer x (1 ≤ x ≤ 10^9).

Output: The only line containing one integer: the answer.
*/

int main(){

    /* Notes:
    - if x is a power of 2, then only 1 bacteria needed 
    - repeatedly subtract x by the greatest power of 2 number that is less than or equal to x until x reaches 0 (count the number of subtractions)
    - equivalent to counting the number of bits set to 1 in binary representation of x
    */

    ll targetNum;
    cin >> targetNum;
    
    ll runningSum = 0;
    while(targetNum > 0){
        // check the least significant bit
        if(targetNum & 1) runningSum++;
        // right shift targetNum
        targetNum = targetNum >> 1;        
    }

    cout << runningSum << endl;
}