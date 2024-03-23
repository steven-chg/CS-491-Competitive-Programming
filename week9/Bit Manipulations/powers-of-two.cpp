#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Powers of Two
A positive integer 𝑥 is called a power of two if it can be represented as 𝑥=2^𝑦, where 𝑦 is a non-negative integer. 
So, the powers of two are 1,2,4,8,16,….

You are given two positive integers 𝑛 and 𝑘. Your task is to represent 𝑛 as the sum of exactly 𝑘 powers of two.

Input: The only line of the input contains two integers 𝑛 and 𝑘 (1≤𝑛≤10^9, 1≤𝑘≤2⋅10^5).

Output: If it is impossible to represent 𝑛 as the sum of 𝑘 powers of two, print NO.

Otherwise, print YES, and then print 𝑘 positive integers 𝑏1,𝑏2,…,𝑏𝑘 such that each of 𝑏𝑖 is a power of two, and ∑(i = 1 to k) 𝑏𝑖=𝑛 . 
If there are multiple answers, you may print any of them.
*/

int main(){
    ll n, k;
    cin >> n >> k;

    // sanity check, if k > n, then impossible, since each k at least has to be 1
    if(k > n) {
        cout << "NO" << endl;
        return 0;
    }

    /* Notes:
    - we can count the number of occurrences of 1's in the binary representation of n and at which index they appear
    - index 0 represents number of 2^0 values, index 3 represents number of 2^3 values; store this information in a 1D bit vector

    - we also track the number of occurrences of 1's in n, which is the minimum number of positive integers needed that sum up to n
    - then we loop through the vector from the highest index position downwards; if index i stores 1, it is equivalent to index i-1 storing 2
    i.e. vector 0 0 1 represents value 4, which can also be expressed by 2 + 2, or vector 0 2 0, which can also be expressed by 1 + 1 + 1 + 1, or vector 4 0 0
    - we loop from highest index position downwards, incrementing minimum number of positive integers that sum up to n until it reaches k
    - then we go through the vector and output the values that actually sum up to n
    */

    // count the number of occurrences of 1's in n, and store into vector
    ll numOccurrences = 0;
    vector<ll> bitVec;
    while(n > 0){
        // check the least significant bit; if 1, increment number of occurrences and set the vector accordingly
        if((n & 1) == 1) {
            numOccurrences++; 
            bitVec.push_back(1);
        } else{
            bitVec.push_back(0);
        }
        // right shift targetNum
        n = n >> 1;   
    }

    // if minimum numbers needed to sum up to n is greater than k, then impossible
    if(numOccurrences > k){
        cout << "NO" << endl;
        return 0;
    }

    // // sanity check bitVec and numOccurrences
    // cout << numOccurrences << endl;
    // for(int i = 0; i < bitVec.size(); i++){
    //     cout << bitVec[i] << " ";
    // }
    // cout << endl;

    // loop through vector from highest index downwards
    for(int i = bitVec.size() - 1; i >= 0; i--){
        // we can represent 1 number at index i with 2 numbers at index i - 1
        if(i > 0){
            while(bitVec[i] > 0 && numOccurrences < k){
                bitVec[i]--;
                bitVec[i-1] += 2;
                numOccurrences++;
            }
        }
        if(numOccurrences == k) break;
    }

    // if we cannot get k numbers that sum up to n
    if(numOccurrences != k){
        cout << "NO" << endl;
        return 0;
    } else{
        cout << "YES" << endl;
        // go through the vector and output the values that sum up to n
        for(int i = 0; i < bitVec.size(); i++){
            for(int j = 0; j < bitVec[i]; j++){
                cout << (1 << i) << " ";
            }
        }
        cout << endl;
    }

}