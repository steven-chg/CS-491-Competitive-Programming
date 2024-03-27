#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Fibonacci Numbers
Given a modulus 𝑚 and an integer 𝑛, compute the 𝑛th Fibonacci number 𝐹𝑛 (mod 𝑚).

Recall that for Fibonacci numbers 𝐹0=𝐹1=1 and 𝐹𝑖=𝐹𝑖−1+𝐹𝑖−2.

Input: The first line contains two space separated numbers, 1≤𝑡≤10000 the number of test cases, and the modulus 10^7<𝑚≤10^9+9.
The next 𝑡 lines contains one number 0≤𝑛𝑖≤10^15.

Output: Output the answer to each test case, 𝐹𝑛𝑖(mod𝑚) on the 𝑖th line of the output.
*/

// Helper function that performs exponentiation through recursive calls on half of exponent 
// i.e. n^8 = n^4 * n^4); if n is odd, multiply by n again at the end (n^9 = n^4 * n^4 * n = n^2 * n^2 * n^2 * n^2 * n)
void exponent(ll matrix[2][2], ll n, ll modulo){
    // base case, if we try to raise to exponent of 0 or 1, we don't perform anything
    if(n == 0 || n == 1) return;

    // recursive call on n/2 exponent 
    exponent(matrix, n/2, modulo);

    // perform matrix multiplication (matrix * matrix)
    ll a = (matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0]) % modulo;
    ll b = (matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1]) % modulo;
    ll c = (matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0]) % modulo;
    ll d = (matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1]) % modulo;
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;

    // if n is odd, then we need to add an additional multiplication with {{1, 1}, {1, 0}}
    if(n % 2 == 1){
        ll a = (matrix[0][0] * 1 + matrix[0][1] * 1) % modulo;
        ll b = (matrix[0][0] * 1 + matrix[0][1] * 0) % modulo;
        ll c = (matrix[1][0] * 1 + matrix[1][1] * 1) % modulo;
        ll d = (matrix[1][0] * 1 + matrix[1][1] * 0) % modulo;
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }
}

// MATRIX EXPONENTIATION
int main(){
    ll numCases, modulo;
    cin >> numCases >> modulo;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll n;
        cin >> n;

        if(n == 0) cout << 1 << endl;
        else if(n == 1) cout << 1 << endl;
        else{
            ll matrix[2][2] = {{1, 1}, {1, 0}};
            // call exponent to raise matrix {{1, 1}, {1, 0}} to the nth power
            exponent(matrix, n, modulo);
            // result will be stored in first row, first column 
            // (technically matrix^n will store Fn+1 in first row and first column, but since we're using the convention where F0 = F1 = 1, Fn is stored in first row and first column)
            cout << matrix[0][0] << endl;      
        }
    }
}