#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Zig Zags
You are given an array 𝑎1,𝑎2…𝑎𝑛. Calculate the number of tuples (𝑖,𝑗,𝑘,𝑙) such that: 1≤𝑖<𝑗<𝑘<𝑙≤𝑛; 𝑎𝑖=𝑎𝑘 and 𝑎𝑗=𝑎𝑙;

Input: The first line contains a single integer 𝑡 (1≤𝑡≤100) — the number of test cases.

The first line of each test case contains a single integer 𝑛 (4≤𝑛≤3000) — the size of the array 𝑎.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛) — the array 𝑎.

It's guaranteed that the sum of 𝑛 in one test doesn't exceed 3000.

Output: For each test case, print the number of described tuples.
*/

int main(){
    int numCases;
    cin >> numCases;

    for(int testNum = 0; testNum < numCases; testNum++){
        int arraySize;
        cin >> arraySize;
        
        ll numTuples = 0;

        // retrieve array
        vector<int> array(arraySize+1);
        for(int index = 0; index < arraySize; index++){
            cin >> array[index];
        }

        // leftOfJCount will store the number of occurrences of each number strictly to the left of the j pointer
        vector<int> leftOfJCount(4000);

        // j will loop from index 0 to arraySize - 1 (essentially find all possible values of j)
        for(int j = 0; j < arraySize; j++){
            // rightOfKCount will track the number of occurrences of each number strictly to the right of the k pointer
            vector<int> rightOfKCount(4000);
            // for each value of j, we loop through all possible values of k (which needs to be strictly to the right of j)
            for(int k = arraySize-1; k > j; k--){
                // we need to find the number of occurrences of the value pointed to by the k pointer on the left of j and value pointed to by the j pointer to the right of k
                // multiply those together is the possible number of tuples for each j and k combination 
                numTuples += rightOfKCount[array[j]] * leftOfJCount[array[k]];
                // increment the number of occurrences of values to the right of k for the value pointed to by current k
                rightOfKCount[array[k]]++;
            }
            // increment the number of occurences of values to the left of j for the value pointed to by current j
            leftOfJCount[array[j]]++;
        }
        cout << numTuples << endl;
    }
}