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

// helper function to find the greatest common divisor between two numbers
int greatestCommonDivisor(ll valueOne, ll valueTwo){
    if(valueTwo > valueOne) return greatestCommonDivisor(valueTwo, valueOne);
    if(valueTwo > 0) return greatestCommonDivisor(valueTwo, valueOne % valueTwo);
    else return valueOne;
}

int main(){
    ll n;
    cin >> n;

    vector<ll> arrayValues;
    // track previous values and additional integers needed to make the array co-prime
    ll previousValue;
    ll additionalIntegers = 0;

    // retrieve values in the array one by one and add in '1' if necessary (if previous number and current number are NOT co-primes)
    for(int integerNum = 0; integerNum < n; integerNum++){
        ll value;
        cin >> value;

        // first value in the array, so just push it into the array
        if(integerNum == 0){
            arrayValues.push_back(value);
        } else if(greatestCommonDivisor(previousValue, value) == 1){
        // case where previous value and current value is co-prime (can just push this new value onto the array)
            arrayValues.push_back(value);
        } else if(greatestCommonDivisor(previousValue, value) > 1){
        // case where the previous value and current value are NOT co-primes, so we push a '1' first (since '1' is co-prime with any positive integer)
            arrayValues.push_back(1);
            arrayValues.push_back(value);
            additionalIntegers++;
        }

        // update the previous value in the end
        previousValue = value;
    }

    // output the results
    cout << additionalIntegers << endl;
    for(int i = 0; i < arrayValues.size(); i++){
        cout << arrayValues[i] << " ";
    }
    cout << endl;

}