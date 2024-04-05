#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Benches
The city park of IT City contains n east to west paths and n north to south paths. 
Each east to west path crosses each north to south path, so there are n^2 intersections.

The city funded purchase of five benches. 
To make it seems that there are many benches it was decided to place them on as many paths as possible. 
Obviously this requirement is satisfied by the following scheme: each bench is placed on a cross of paths and each path 
contains not more than one bench.

Help the park administration count the number of ways to place the benches.

Input: The only line of the input contains one integer n (5 ≤ n ≤ 100) — the number of east to west paths and north to south paths.

Output: Output one integer — the number of ways to place the benches.
*/

// helper function to find combinations n Choose k
ll combinations(ll n, ll k){
    ll result = 1;
    for(ll i = 1; i <= k; i++){
        // this formula is derived where the numerator takes into account some terms in n! cancel out with terms in (n-k)! 
        // (specifically the (n-k)! terms all cancel out, so numerator starts from (n - k + 1) up to (n - k + k, or n)); denominator is just k!
        result = result * (n - k + i) / i;
    }
    return result;
}

int main(){
    ll n;
    cin >> n;

    /* Notes:
    - first choose 5 paths out of n E to W or N to S paths that will contain benches
    - then out of those 5 paths, choose ways to place the 5 benches (first bench has n options, second bench has n - 1 options, and so on until we place all 5)
    */

    ll numWays = combinations(n, 5);
    for(int i = 0; i < 5; i++){
        numWays *= n;
        n--;
    }

    cout << numWays << endl;
}