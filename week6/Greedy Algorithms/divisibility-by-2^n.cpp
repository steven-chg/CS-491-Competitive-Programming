#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Divisibility by 2^n
You are given an array of positive integers 𝑎1,𝑎2,…,𝑎𝑛.
Make the product of all the numbers in the array (that is, 𝑎1⋅𝑎2⋅…⋅𝑎𝑛) divisible by 2^𝑛.

You can perform the following operation as many times as you like:
    select an arbitrary index 𝑖 (1≤𝑖≤𝑛) and replace the value 𝑎𝑖 with 𝑎𝑖=𝑎𝑖⋅𝑖.

You cannot apply the operation repeatedly to a single index. In other words, all selected values of 𝑖 must be different.

Find the smallest number of operations you need to perform to make the product of all the elements in the array divisible by 2^𝑛. 
Note that such a set of operations does not always exist.

Input: The first line of the input contains a single integer 𝑡 (1≤𝑡≤10^4) — the number test cases.

Then the descriptions of the input data sets follow.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤2⋅10^5) — the length of array 𝑎.

The second line of each test case contains exactly 𝑛 integers: 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10^9).

It is guaranteed that the sum of 𝑛 values over all test cases in a test does not exceed 2⋅10^5.

Output: For each test case, print the least number of operations to make the product of all numbers in the array divisible by 2^𝑛. 
If the answer does not exist, print -1.
*/

/* function that calculates the number of 2's in 'value' */
// i.e. if 'value' = 8, return 3 (8 = 2 x 2 x 2)
ll twoFactor(ll value){
    ll count = 0;
    while(value % 2 == 0){
        count++;
        value /= 2;
    }
    return count;
}

int main(){
    ll numCases;
    scanf("%lld", &numCases);

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll arrayLength;
        scanf("%lld", &arrayLength);

        /* Notes:
        - we only care about how many times 2 appears in the multiplication of all the values together
        - i.e. if the number of times 2 appears in the multiplication is >= arrayLength, then it is possible to make product of all values
        (potentially including multiplication with indices) a multiple of 2^arrayLength
        - where for a value 22, 22 = 2x11 (2 appears once), 8 = 2x2x2 (2 appears 3 times)
        */

        ll numTwos = 0;                     // number of 2s appearing in all values in the array
        ll allPossibleNumTwos = 0;          // number of 2s appearing while also accounting for multiplying by index (1 indexed)
        vector<ll> indexTwos;               // vector to store number of 2's from each index (we will sort then add until allPossibleNumTwos exceeds or = arrayLength)

        // retrieve all values in the array and calculate number of 2's (appear in value and also in indices)
        for(int index = 1; index <= arrayLength; index++){
            ll currentValue;
            cin >> currentValue;
            numTwos += twoFactor(currentValue);
            ll indexNumTwos = twoFactor(index);
            indexTwos.push_back(indexNumTwos);
            allPossibleNumTwos += indexNumTwos;
        }

        allPossibleNumTwos += numTwos;
        sort(indexTwos.begin(), indexTwos.end(), greater<ll>());            // sort in descending order to minimize number of operations

        // original product of array values already divisible by 2^n
        if(numTwos >= arrayLength){
            cout << "0" << endl;
            continue;
        }

        // impossible to make product of arrays (and indices) divisible by 2^n
        if(allPossibleNumTwos < arrayLength){
            cout << "-1" << endl;
            continue;
        }

        // calculate number of operations (continue to add number of two's given by multiplying with indices until it exceeds or = arrayLength)
        ll numOperations = 0;
        while(numTwos < arrayLength){
            numTwos += indexTwos[numOperations];
            numOperations++;
        }
        cout << numOperations << endl;
    }
}