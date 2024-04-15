#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Point Update, Range Query
Nasa has a list of numbers 𝑎1,𝑎2,...,𝑎𝑛, and he wants to support two operations:
    Given 𝑖 and 𝑣, add 𝑣 to 𝑎𝑖.
    Given 𝑙 and 𝑟, find the sum ∑(i=l to r) 𝑎𝑖.

Initially, every number in the list is 0.

Input: The first line of input contains two space-separated integers 𝑛 and 𝑚 (1≤𝑛,𝑚≤10^5), representing the length of the array, and the number of operations that Nasa will perform respectively.

Each of the next 𝑚 lines contains three space-separated integers that describe a query. The first integer is 𝑡∈{1,2}, which represents the type of operation.

If 𝑡=1, then the next two integers are 𝑖 and 𝑣 (1≤𝑖≤𝑛 and −10^7≤𝑣≤10^7). Nasa performs the first operation.
If 𝑡=2, then the next two integers are 𝑙 and 𝑟 (1≤𝑙≤𝑟≤𝑛). Nasa performs the second operation.

Note that the queries should be performed in the order they are given in the input.

We recommend you try and solve this problem with square root decomposition.

Output
After each query of type 2, output the sum ∑(i=l to r)𝑎𝑖.
*/

int main(){
    ll arrayLength, numOperations;
    cin >> arrayLength >> numOperations;

    /* Notes:
    - we need a separate array to handle each block of sqrt(arrayLength) size; stores the sum of the entire block
    */

    // initialize everything to zero
    vector<ll> rawData(arrayLength, 0);
    ll blockSize = sqrt(arrayLength);
    vector<ll> sqrtData(arrayLength/blockSize, 0); 
    if(arrayLength % blockSize != 0){
        sqrtData.push_back(0);
    }

    for(ll operation = 0; operation < numOperations; operation++){
        int t;
        ll iORl, vORr;
        cin >> t >> iORl >> vORr;

        if(t == 1){
        // operation 1; add v to ai (add to both the raw data array as well as the square root data array)
            ll zeroIndex = iORl - 1;
            rawData[zeroIndex] += vORr;
            ll squareRootIndex = zeroIndex/blockSize;
            sqrtData[squareRootIndex] += vORr;
        } else if(t == 2){
        // operation 2
            ll zeroLeftIndex = iORl - 1;
            ll zeroRightIndex = vORr - 1;
            ll sum = 0;

            // add up data on the left side that don't comprise full square root data blocks (zeroLeftIndex % blockSize != 0 ensures that the left index is the 1st cell (0-indexed cells) encompassed by a block or beyond)
            while((zeroLeftIndex <= zeroRightIndex) && (zeroLeftIndex % blockSize != 0)){
                sum += rawData[zeroLeftIndex];
                // update left index by 1
                zeroLeftIndex++;
            }
            // add up data that fill up entire blocks (make sure that the right index is at least at the end of the current block by comparing with leftIndex + blockSize - 1)
            while((zeroLeftIndex + blockSize - 1 <= zeroRightIndex)){
                sum += sqrtData[zeroLeftIndex / blockSize];
                // update left index by block size; move on to the next block
                zeroLeftIndex += blockSize;
            }
            // add up data on the right side that don't comprise full square root data blocks (whatever is remaining between current left index and the right index)
            while(zeroLeftIndex <= zeroRightIndex){
                sum += rawData[zeroLeftIndex];
                // update left index by 1
                zeroLeftIndex++;
            }
            cout << sum << endl;
        }
    }
}