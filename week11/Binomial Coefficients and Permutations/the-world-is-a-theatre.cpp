#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* The World is a Theatre
There are n boys and m girls attending a theatre club. 
To set a play "The Big Bang Theory", they need to choose a group containing exactly t actors containing no less than 
4 boys and no less than one girl. How many ways are there to choose a group? 
Of course, the variants that only differ in the composition of the troupe are considered different.

Perform all calculations in the 64-bit type: long long for С/С++, int64 for Delphi and long for Java.

Input: The only line of the input data contains three integers n, m, t (4 ≤ n ≤ 30, 1 ≤ m ≤ 30, 5 ≤ t ≤ n + m).

Output: Find the required number of ways.

Please do not use the %lld specificator to read or write 64-bit integers in С++. 
It is preferred to use cin, cout streams or the %I64d specificator.
*/

// helper function to find combinations n Choose k
ll combinations(ll n, ll k){
    ll result = 1;
    for(ll i = 1; i <= k; i++){
        result = result * (n - k + i) / i;
    }
    return result;
}

int main(){
    ll n, m, t;
    cin >> n >> m >> t;

    /* Notes:
    - start with 4 boys and t - 4 girls, then 5 boys and t - 5 girls, until there are t - 1 boys and 1 girl (or until number of boys exceeds n) 
    find these combinations and sum them up
    */

    ll totalWays = 0;
    for(ll numBoys = 4; numBoys <= t - 1; numBoys++){
        ll numGirls = t - numBoys;
        // if we are trying to choose more girls than there exists, then we need to continue to the next numBoys choice
        if(!(numGirls <= m)) continue;

        // find current n Choose numBoys and current n Choose numGirls
        ll boysComb = combinations(n, numBoys);
        ll girlsComb = combinations(m, numGirls);
        totalWays += boysComb*girlsComb;

        // break out of loop if numBoys == n
        if(numBoys == n) break;
    }

    cout << totalWays << endl;
}

// /* FAILS TEST CASE SINCE FACTORIAL CAN OVERFLOW (factorial(30) OVERFLOWS)) */
// // helper function to find factorial
// ll factorial(ll value){
//     ll factorial = 1;
//     for(ll i = 1; i <= value; i++){
//         factorial *= i;
//     }
//     return factorial;
// }

// int main(){
//     ll n, m, t;
//     cin >> n >> m >> t;

//     /* Notes:
//     - start with 4 boys and t - 4 girls, then 5 boys and t - 5 girls, until there are t - 1 boys and 1 girl (or until number of boys exceeds n) 
//     find these combinations and sum them up
//     */

//     ll totalWays = 0;
//     for(ll numBoys = 4; numBoys <= t - 1; numBoys++){
//         ll numGirls = t - numBoys;
//         // if we are trying to choose more girls than there exists, then we need to continue to the next numBoys choice
//         if(!(numGirls <= m)) continue;

//         // find current n Choose numBoys and current n Choose numGirls
//         ll boysComb = factorial(n) / (factorial(numBoys) * factorial(n - numBoys));
//         ll girlsComb = factorial(m) / (factorial(numGirls) * factorial(m - numGirls));
//         totalWays += boysComb*girlsComb;

//         // break out of loop if numBoys == n
//         if(numBoys == n) break;
//     }

//     cout << totalWays << endl;
// }