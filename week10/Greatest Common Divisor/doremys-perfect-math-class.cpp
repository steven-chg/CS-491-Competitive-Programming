#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Doremy's Perfect Math Class
"Everybody! Doremy's Perfect Math Class is about to start! Come and do your best if you want to have as much IQ as me!" 
In today's math class, Doremy is teaching everyone subtraction. Now she gives you a quiz to prove that you are paying attention in class.

You are given a set 𝑆 containing positive integers. You may perform the following operation some (possibly zero) number of times:
    choose two integers 𝑥 and 𝑦 from the set 𝑆 such that 𝑥>𝑦 and 𝑥−𝑦 is not in the set 𝑆.
    add 𝑥−𝑦 into the set 𝑆.
You need to tell Doremy the maximum possible number of integers in 𝑆 if the operations are performed optimally. 
It can be proven that this number is finite.

Input: The input consists of multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤10^4) — the number of test cases. 
The description of the test cases follows.

The first line contains an integer 𝑛 (2≤𝑛≤10^5) — the size of the set 𝑆.

The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎1<𝑎2<⋯<𝑎𝑛≤10^9) — the positive integers in 𝑆.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅10^5.

Output: For each test case, you need to output the maximum possible number of integers in 𝑆. It can be proven that this value is finite.
*/

// helper function to find the greatest common divisor between two numbers
int greatestCommonDivisor(ll valueOne, ll valueTwo){
    if(valueTwo > valueOne) return greatestCommonDivisor(valueTwo, valueOne);
    if(valueTwo > 0) return greatestCommonDivisor(valueTwo, valueOne % valueTwo);
    else return valueOne;
}

int main(){
    ll numCases;
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll setSize;
        cin >> setSize;

        // retrieve the original integer set and find the greatest common divisor of all the values in the set
        ll gcd;
        ll largestVal;
        for(int i = 0; i < setSize; i++){
            ll newVal;
            cin >> newVal;

            // if its the first integer, then just set the gcd to this new value
            if(i == 0){
                gcd = newVal;
            }
            else{
            // else, we need to find the new gcd of the integer set
                gcd = greatestCommonDivisor(gcd, newVal);
            }

            // keep track of the largest value in the original integer set
            if(i == setSize - 1) largestVal = newVal;
        }

        /* Note:
        - find the greatest common divisor of all the values in the original integer set 
        - possible values that can be within the set are any multiples of the GCD less than or equal to the largest value
        */

        cout << largestVal / gcd << endl;
    }
}