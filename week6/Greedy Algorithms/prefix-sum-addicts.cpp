#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Prefix Sum Addicts
Suppose 𝑎1,𝑎2,…,𝑎𝑛 is a sorted integer sequence of length 𝑛 such that 𝑎1≤𝑎2≤⋯≤𝑎𝑛.

For every 1≤𝑖≤𝑛, the prefix sum 𝑠𝑖 of the first 𝑖 terms 𝑎1,𝑎2,…,𝑎𝑖 is defined by 𝑠𝑖=∑(k = 1 to k = i) 𝑎𝑘 = 𝑎1+𝑎2+⋯+𝑎𝑖.
Now you are given the last 𝑘 terms of the prefix sums, which are 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛. Your task is to determine whether this is possible.

Formally, given 𝑘 integers 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛, the task is to check whether there is a sequence 𝑎1,𝑎2,…,𝑎𝑛 such that
    1. 𝑎1≤𝑎2≤⋯≤𝑎𝑛, and
    2. 𝑠𝑖=𝑎1+𝑎2+⋯+𝑎𝑖 for all 𝑛−𝑘+1≤𝑖≤𝑛.

Input: Each test contains multiple test cases. The first line contains an integer 𝑡 (1≤𝑡≤10^5) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains two integers 𝑛 (1≤𝑛≤10^5) and 𝑘 (1≤𝑘≤𝑛), indicating the length of the sequence 𝑎 and the number of terms of prefix sums, respectively.

The second line of each test case contains 𝑘 integers 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛 (−10^9≤𝑠𝑖≤10^9 for every 𝑛−𝑘+1≤𝑖≤𝑛).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 10^5.

Output: For each test case, output "YES" (without quotes) if it is possible and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).
*/

int main(){
    ll numCases;
    cin >> numCases;

    /* Notes:
    - we can work backwards
    - find the largest value in the sorted sequence (by performing sn - s(n-1))
    - then check the second largest value in the sorted sequence (by performing s(n-1) - s(n-2))
    - if the second largest value isn't smaller or equal to the largest value, then it is impossible
    - work like this downwards to check all the prefix sums
    - once we check all the prefix sums, then we grab the last prefix sum and distribute the value stored...
    inside evenly among the remaining spaces in the array 
    */

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll length, numPrefix;
        cin >> length >> numPrefix;

        // get all prefixes
        vector<ll> prefix;
        for(ll i = 0; i < numPrefix; i++){
            ll currentPrefix;
            cin >> currentPrefix;
            prefix.push_back(currentPrefix);
        }

        ll upperBound;
        bool onlyOnePrefix = true;
        bool prefixClash = false;
        //go through all prefix sums and check to make sure all values that appear later in the sequences are greater or equal to values that appear before
        for(ll prefixNum = (numPrefix - 1); prefixNum > 0; prefixNum--){
            // find the largest value in sequence
            if(prefixNum == (numPrefix - 1)){
                upperBound = prefix[prefixNum] - prefix[prefixNum - 1];
                onlyOnePrefix = false;
            } else{
                // find the previous value in the sequence and make sure it isn't greater than its next value
                if(prefix[prefixNum] - prefix[prefixNum - 1] > upperBound){
                    prefixClash = true;
                    break;
                }
                // if previous value isn't greater than its next value, update upperBound to the previous value
                upperBound = prefix[prefixNum] - prefix[prefixNum - 1];
            }
        }

        if(prefixClash){
            cout << "NO" << endl;
            continue;
        }

        // if onlyOnePrefix == true, then output "YES" since it should be possible to get to that prefix with no restrictions on the sequence of numbers
        if(onlyOnePrefix){
            cout << "YES" << endl;
            continue;
        }

        // at this point, if onlyOnePrefix == false, then upperBound stores the max. value that can be seen in the the sequence in positions 1 to n-k+1 (inclusive)
        // and prefix[0] stores the value that values in position 1 to n-k+1 (inclusive) need to sum up to

        bool possible;
        // first divide (floor) remaining prefix sum by number of available spots in the array
        ll minValueToAchievePrefix = prefix[0] / (length - numPrefix + 1);
        // check if the remaining prefix sum divided by number of available spots has a remainder (if yes, then it means we need to add 1 to minValueToAchievePrefix)
        if((prefix[0] % (length - numPrefix + 1)) > 0){
            if((minValueToAchievePrefix + 1) > upperBound) possible = false;
            else possible = true;        
        } else{
            if((minValueToAchievePrefix) > upperBound) possible = false;
            else possible = true;
        }

        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

