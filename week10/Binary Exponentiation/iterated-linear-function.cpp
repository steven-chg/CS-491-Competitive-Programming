#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Iterated Linear Function
Consider a linear function f(x) = Ax + B. 
Let's define g(0)(x) = x and g(n)(x) = f(g(n - 1)(x)) for n > 0. For the given integer values A, B, n and x find the value of g(n)(x) modulo 10^9 + 7.

Input: The only line contains four integers A, B, n and x (1 ≤ A, B, x ≤ 10^9, 1 ≤ n ≤ 10^18) — the parameters from the problem statement.

Note that the given value n can be too large, so you should use 64-bit integer type to store it. 
In C++ you can use the long long integer type and in Java you can use long integer type.

Output: Print the only integer s — the value g(n)(x) modulo 10^9 + 7.
*/

// Helper function that performs exponentiation through recursive calls on half of exponent 
// i.e. n^8 = n^4 * n^4); if n is odd, multiply by n again at the end (n^9 = n^4 * n^4 * n = n^2 * n^2 * n^2 * n^2 * n)
void exponent(ll matrix[2][2], ll n, ll modulo, ll A, ll B){
    // base case, if we try to raise to exponent of 0 or 1, we don't perform anything
    if(n == 0 || n == 1) return;

    // recursive call on n/2 exponent 
    exponent(matrix, n/2, modulo, A, B);

    // perform matrix multiplication (matrix * matrix)
    ll a = (matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0]) % modulo;
    ll b = (matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1]) % modulo;
    ll c = (matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0]) % modulo;
    ll d = (matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1]) % modulo;
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;

    // if n is odd, then we need to add an additional multiplication with {{A, B}, {0, 1}}
    if(n % 2 == 1){
        ll a = (matrix[0][0] * A + matrix[0][1] * 0) % modulo;
        ll b = (matrix[0][0] * B + matrix[0][1] * 1) % modulo;
        ll c = (matrix[1][0] * A + matrix[1][1] * 0) % modulo;
        ll d = (matrix[1][0] * B + matrix[1][1] * 1) % modulo;
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }
}

int main(){
    ll A, B, n, x;
    cin >> A >> B >> n >> x;
    
    ll modulo = 1e9 + 7;

    /* Notes:
    - g(2)(x) = f(g(1)(x)) = f(f(g(0)(x))) = f(f(x)) 
    - In other words, we need to apply the linear function n times on x
    - if n == 1, {{A, B}, {0, 1}} x {x, 1} = {Ax+B, 1}
    - if n == 2, {{A, B}, {0, 1}}^2 x {x, 1} = {{A*A + B*0, A*B + B*1}, {0*A + 1*0, 0*B + 1*1}} = {{A*A, AB + B}, {0, 1}} x {x, 1} = {{A^2*x + AB + B, 1}}
    {{A, B}, {0, 1}} x {Ax+B, 1} = {A(Ax+B) + B, 1}
    */

    ll matrix[2][2] = {{A, B}, {0, 1}};
    // call exponent to raise matrix {{A, B}, {0, 1}} to the nth power
    exponent(matrix, n, modulo, A, B);
    // multiply matrix with {x, 1} to get result and output it
    ll output = (matrix[0][0] * x + matrix[0][1]) % modulo; 
    cout << output << endl;
}