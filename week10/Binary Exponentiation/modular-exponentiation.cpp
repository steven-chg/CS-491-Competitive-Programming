#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Modular Exponentiation
Given a modulus 𝑚, compute 𝑎^𝑏(mod 𝑚).

Input: The first line contains two space separated numbers, 1≤𝑡≤10000 the number of test cases, and the modulus 10^7<𝑚≤10^9+9.

The next 𝑡 lines contains two space separated numbers 𝑎𝑖 and 𝑏𝑖 with 0≤𝑎𝑖,𝑏𝑖≤10^9.

Output: Output the answer to each test case, 𝑎i^𝑏𝑖(mod𝑚) on the 𝑖th line of the output.
*/

int main(){
    ll numCases, modulo;
    cin >> numCases >> modulo;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll fact, exponent;
        cin >> fact >> exponent;

        // TRICK: use a binary representation of the exponent
        // e.g. 22 is 10110 in binary representation; 3^22 = 3^10110(base 2) = 3^10000(base 2) x 3 ^00100(base 2) x 3^00010(base 2) = 3^16 x 3^4 x 3^2
        ll out = 1;
        while(exponent > 0){
            // if the exponent has least significant bit 1, then multiply output by current factorial
            if(exponent & 1){
                out *= fact;
                // maintain modulo to avoid overflow
                out %= modulo;
            }
            // update the factorial every time; e.g. 1 --> 3 --> 9 --> 27 --> 81 in the above example 
            fact *= fact;
            // maintain modulo to avoid overflow
            fact %= modulo;
            // right shift the exponent to look at next least significant bit
            exponent >>= 1;
        }

        cout << out << endl;
    }
}