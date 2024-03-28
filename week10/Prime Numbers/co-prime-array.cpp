#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Co-Prime Array
You are given an array of n elements, you must make it a co-prime array in as few moves as possible.

In each move you can insert any positive integral number you want not greater than 10^9 in any place in the array.

An array is co-prime if any two adjacent numbers of it are co-prime.

In the number theory, two integers a and b are said to be co-prime if the only positive integer that divides both of them is 1.

Input: The first line contains integer n (1 ≤ n ≤ 1000) — the number of elements in the given array.
The second line contains n integers ai (1 ≤ ai ≤ 10^9) — the elements of the array a.

Output: Print integer k on the first line — the least number of elements needed to add to the array a to make it co-prime.
The second line should contain n + k integers aj — the elements of the array a after adding k elements to it. 
Note that the new array should be co-prime, so any two adjacent values should be co-prime. 
Also the new array should be got from the original array a by adding k elements to it.

If there are multiple answers you can print any one of them.
*/

int main(){
    ll n;
    cin >> n;

    // retrieve the initial array
    vector<ll> arrayValues;
    for(int integerNum = 0; integerNum < n; integerNum++){
        ll value; 
        cin >> value;
        arrayValues.push_back(value);
    }

}