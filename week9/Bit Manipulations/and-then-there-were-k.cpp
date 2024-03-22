#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* And Then There Were K
Given an integer 𝑛, find the maximum value of integer 𝑘 such that the following condition holds:
    𝑛 & (𝑛−1) & (𝑛−2) & (𝑛−3) & ... (𝑘) = 0
where & denotes the bitwise AND operation.

Input: The first line contains a single integer 𝑡 (1≤𝑡≤3⋅10^4). Then 𝑡 test cases follow.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤10^9).

Output: For each test case, output a single integer — the required integer 𝑘.
*/

int main(){
    ll numCases;
    cin >> numCases;

    /* Notes:
    - if n is a power of 2, then k can be n - 1
    - other example cases
    10 is 1010 & 9 is 1001 = 1000 & 8 is 1000 = 1000 & 7 is 0111 = 0000
    12 is 1100 & 11 is 1011 = 1000 & 10 is 1010 = 1000 & 9 is 1001 = 1000 ... & 7 is 0111 = 0000

    - observe that we need to find the largest power of 2 value that is less than or equal to n and subtract that by 1 to give maximum integer k
    */

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll n;
        cin >> n;

        // find the index of the most significant 1 bit of the binary representation of n (0 indexed)
        ll largestIndex = 0;
        while(n > 1){
            n = n >> 1;
            largestIndex++;
        }
        
        // find the 2^(largestIndex), which is the largest power of 2 value that is less than or equal to n, then subtract that by 1 to get max k
        ll maxK = (1 << (largestIndex)) - 1;

        cout << maxK << endl;
    }  
}

// /* TIME LIMIT EXCEEDED */
// int main(){
//     ll numCases;
//     cin >> numCases;

//     for(int caseNum = 0; caseNum < numCases; caseNum++){
//         ll n;
//         cin >> n;

//         ll maxK = n;
//         while(n != 0 && maxK > 0){
//             n = n & maxK;
//             if(n != 0) maxK--;
//         }

//         cout << maxK << endl;
//     }  
// }