#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Extended Euclidean Algorithm and Bezout's Identity
Bézout's identity states that for any positive integer 𝑎 and 𝑏, there exists integers 𝑥 and 𝑦 such that:
[ax+by = GCD(a,b).]

What if we are given integers 𝑎, 𝑏, and 𝑐, and we wish to find integers 𝑥 and 𝑦 such that:
[ax+by = c.]

Find the pair (𝑥,𝑦) satisfying this equation with the minimum possible 𝑥≥0 or determine that this is not possible.

Input: The first and only line contains integers 𝑎 and 𝑏 and 𝑐 with 1≤𝑎,𝑏,𝑐≤10^9.

Output: Output a pair of space seperated integers 𝑥 and 𝑦 where 𝑥 is the minimum 𝑥≥0 that satisfies 𝑎𝑥+𝑏𝑦=𝑐.
*/

// helper function to find the greatest common divisor between two numbers
int greatestCommonDivisor(ll valueOne, ll valueTwo){
    if(valueTwo > valueOne) return greatestCommonDivisor(valueTwo, valueOne);
    if(valueTwo > 0) return greatestCommonDivisor(valueTwo, valueOne % valueTwo);
    else return valueOne;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    
    // find gcd of a and b and initialize x to 0
    ll gcdAB = greatestCommonDivisor(a, b);
    ll x = 0;
    ll y;

    // if c is not a multiple of GCD(a, b), then it is not possible (based on Bezout's Identity)
    if(c % gcdAB != 0){
        cout << -1 << endl;
    } else{
    // once we can confirm that ax + by = c holds true for some x and y values, we loop through possible x values from 0 (inclusive) and check if the resulting y is an integer
        while(1){
            // if ax + by = c holds for current x value, then find the corresponding y value and break
            if((c - a*x) % b == 0){
                y = (c - x*a) / b;
                break;
            }
            // otherwise, try the next x value
            x++;
        }
        cout << x << " " << y << endl;
    }
}