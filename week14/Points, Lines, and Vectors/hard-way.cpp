#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Hard Way
Sam lives in Awesomeburg, its downtown has a triangular shape. Also, the following is true about the triangle:
    its vertices have integer coordinates,
    the coordinates of vertices are non-negative, and
    its vertices are not on a single line.
He calls a point on the downtown's border (that is the border of the triangle) safe if he can reach this point from at least one point of the line 𝑦=0 
walking along some straight line, without crossing the interior of the triangle.

Find the total length of the unsafe parts of the downtown border. It can be proven that these parts are segments and their number is finite.

Input: Each test contains multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of test cases. 
Description of the test cases follows.

Each test case contains three lines, each of them contains two integers 𝑥𝑖, 𝑦𝑖 (0≤𝑥𝑖,𝑦𝑖≤10^9) — coordinates of the vertices of the downtown's border.

Output: For each test case print a single number — the answer to the problem.

Your answer will be considered correct if its absolute or relative error does not exceed 10^−9. Formally let your answer be 𝑎, jury answer be 𝑏. 
Your answer will be considered correct if |𝑎−𝑏| / max(1,|𝑏|) ≤ 10^−9.
*/

int main(){
    ll numCases; 
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        /* Notes:
        - the only unreachable line segment would be one parallel to y = 0 and has a point below it (at a lower y position)
        */

        if(y1 == y2 && y3 < y1){
            // segments 12 can't be reached
            cout << abs(x2 - x1) << endl;
        } else if (y2 == y3 && y1 < y2){
            // segment 23 can't be reached
            cout << abs(x3 - x2) << endl;
        } else if (y1 == y3 && y2 < y1){
            // segment 13 can't be reached
            cout << abs(x3 - x1) << endl;
        } else{
            // all segments can be reached
            cout << 0 << endl;
        }
    }
}