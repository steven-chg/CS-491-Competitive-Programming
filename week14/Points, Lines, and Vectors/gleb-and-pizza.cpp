#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Gleb and Pizza
Gleb ordered pizza home. When the courier delivered the pizza, he was very upset, because several pieces of sausage lay on the crust, 
and he does not really like the crust.

The pizza is a circle of radius r and center at the origin. Pizza consists of the main part — circle of radius r - d with center at the origin, 
and crust around the main part of the width d. Pieces of sausage are also circles. The radius of the i -th piece of the sausage is ri, 
and the center is given as a pair (xi, yi).

Gleb asks you to help determine the number of pieces of sausage caught on the crust. 
A piece of sausage got on the crust, if it completely lies on the crust.

Input: First string contains two integer numbers r and d (0 ≤ d < r ≤ 500) — the radius of pizza and the width of crust.
Next line contains one integer number n — the number of pieces of sausage (1 ≤ n ≤ 10^5).
Each of next n lines contains three integer numbers xi, yi and ri ( - 500 ≤ xi, yi ≤ 500, 0 ≤ ri ≤ 500), where xi and yi are coordinates of the 
center of i-th peace of sausage, ri — radius of i-th peace of sausage.

Output: Output the number of pieces of sausage that lay on the crust.
*/

int main(){
    // NOTE: Use long double for precision since the answer can come down to decimal points (using long long fails test cases)
    long double radius, width;
    cin >> radius >> width;
    ll numSausages;
    cin >> numSausages;

    ll onCrust = 0;
    // loop through all sausages and check if they lay on the crust
    for(ll sausageNum = 0; sausageNum < numSausages; sausageNum++){
        long double x, y, r;
        cin >> x >> y >> r;

        // find the distance between the center of the sausage and the pizza 
        long double distance = sqrt(x*x + y*y);

        // if distance - r >= radius - width AND distance + r <= radius, then this sausage is fully on the crust
        if((distance - r) >= (radius - width) && (distance + r) <= radius) onCrust++;
    }

    cout << onCrust << endl;
}