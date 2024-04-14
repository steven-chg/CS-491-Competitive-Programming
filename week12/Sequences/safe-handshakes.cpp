#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Safe Handshakes
Suppose 2𝑛 people are standing in a circle and want to shake hands with each other. 
It is bad luck if one handshake crosses another one, and we all want to avoid bad luck when we can. Your job is to determine how many ways there are for a group of 2𝑛
people to shake hands (in pairs) without any one handshake crossing another.

For example, a group of four people arranged in a circle in order 1,2,3,4 could have two possibilities: 1 and 2, 3 and 4, or else 1 and 4, 2 and 3.

Input: You are given a single integer 1≤𝑛≤20 where 𝑛 is the number of pairs of people who want to shake hands.

Output: Output a single integer expressing the number ways the group of people can shake hands.

Note: Based on a problem hosted on UVa. Details (for non-students!) available upon request.
*/

int main(){
    ll numPairs;
    cin >> numPairs;

    /* Catalan Numbers */
    vector<ll> catalanNumbers;
    catalanNumbers.push_back(1);            // initialize catalanNumbers[0] = 1 

    // calculate catalan numbers for index up to numPairs of people involved in handshakes 
    for(ll pairNum = 1; pairNum <= numPairs; pairNum++){
        ll currentNum = ((2*pairNum-1) * (2*pairNum) * catalanNumbers[pairNum-1]) / ((pairNum+1) * pairNum);
        catalanNumbers.push_back(currentNum);
    }    

    cout << catalanNumbers[numPairs] << endl;
}