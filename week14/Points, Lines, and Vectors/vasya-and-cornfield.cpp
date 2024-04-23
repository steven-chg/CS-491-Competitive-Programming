#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Vasya and Cornfield
Vasya owns a cornfield which can be defined with two integers 𝑛 and 𝑑. 
The cornfield can be represented as rectangle with vertices having Cartesian coordinates (0,𝑑),(𝑑,0),(𝑛,𝑛−𝑑) and (𝑛−𝑑,𝑛).

Vasya also knows that there are 𝑚 grasshoppers near the field (maybe even inside it). The 𝑖-th grasshopper is at the point (𝑥𝑖,𝑦𝑖). 
Vasya does not like when grasshoppers eat his corn, so for each grasshopper he wants to know whether its position is 
inside the cornfield (including the border) or outside.

Help Vasya! For each grasshopper determine if it is inside the field (including the border).

Input: The first line contains two integers 𝑛 and 𝑑 (1≤𝑑<𝑛≤100).

The second line contains a single integer 𝑚 (1≤𝑚≤100) — the number of grasshoppers.

The 𝑖-th of the next 𝑚 lines contains two integers 𝑥𝑖 and 𝑦𝑖 (0≤𝑥𝑖,𝑦𝑖≤𝑛) — position of the 𝑖-th grasshopper.

Output: Print 𝑚 lines. The 𝑖-th line should contain "YES" if the position of the 𝑖-th grasshopper lies inside or on the border of the cornfield. 
Otherwise the 𝑖-th line should contain "NO".

You can print each letter in any case (upper or lower).
*/

int main(){
    long double n, d;
    cin >> n >> d;

    int numGrassHoppers;
    cin >> numGrassHoppers;
    for(int grassHopper = 0; grassHopper < numGrassHoppers; grassHopper++){
        long double x, y;
        cin >> x >> y;

        /* Notes:
        - break the field into sections

        IF n - d > d (CHECKED)
        1st section (from x = 0 to x = d) is bounded at the bottom by the line y = -1*x + d and at the top by the line y = 1*x + d 
        2nd section (from x = d to x = n - d) is bounded at the top by the line y = 1*x + d and at the bottom by the line y = 1*x + (-d)
        3rd section (from x = n - d to x = n) is bounded at the top by the line y = -1*x + (2*n - d) and at the bottom by the line y = 1*x + (-d)

        IF n - d = d (CHECKED)
        1st section (from x = 0 to x = n - d or x = d) is bounded at the bottom by the line y = -1*x + d and at the top by the line y = 1*x + d
        2nd section (from x = n - d or x = d to x = n) is bounded at the bottom by the line y = 1*x + (-d) and at the top by the line y = -1*x +(2*n - d)

        IF n - d < d
        1st section (from x = 0 to x = n - d) is bounded at the bottom by the line y = -1*x + d and at the top by y = 1*x + d
        2nd section (from x = n - d to x = d) is bounded at the bottom by the line y = -1*x + d and at the top by y = -1*x + (2*n - d)
        3rd section (from x = d to x = n) is bounded at the bottom by y = 1*x + (-d) and at the top by the line y = -1*x + (2*n - d)
        */

        if(n - d > d){
            if(0 <= x && x <= d){
                // check first section
                if(-1*x + d <= y && y <= x + d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else if (d <= x && x <= n - d){
                // check second section
                if(x - d <= y && y <= x + d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else if (n - d <= x && x <= n){
                // check third section
                if(x - d <= y && y <= -1*x + 2*n - d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else{
                cout << "NO" << endl;
            }
        } else if(n - d == d){
            if(0 <= x && x <= d){
                // check first section
                if(-1*x + d <= y && y <= x + d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else if(d <= x && x <= n){
                // check second section
                if(x - d <= y && y <= -1*x + 2*n - d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else{
                cout << "NO" << endl;
            }
        } else if (n - d < d){
            if(0 <= x && x <= n - d){
                // check first section
                if(-1*x + d <= y && y <= x + d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else if(n - d <= x && x <= d){
                // check second section
                if(-1*x + d <= y && y <= -1*x + 2*n - d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            } else if(d <= x && x <= n){
                // check third section
                if(x - d <= y && y <= -1*x + 2*n - d){
                    cout << "YES" << endl;
                } else{
                    cout << "NO" << endl;
                }
            }
        }
    }
}
