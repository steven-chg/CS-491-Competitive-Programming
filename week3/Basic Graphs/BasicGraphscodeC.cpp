#include <bits/stdc++.h>

using namespace std;

/* Love Triangle
As you could know there are no male planes nor female planes. However, each plane on Earth likes some other plane. 
There are n planes on Earth, numbered from 1 to n, and the plane with number i likes the plane with number fi, where 1 ≤ fi ≤ n and fi ≠ i.

We call a love triangle a situation in which plane A likes plane B, plane B likes plane C and plane C likes plane A. 
Find out if there is any love triangle on Earth.

Input: The first line contains a single integer n (2 ≤ n ≤ 5000) — the number of planes.
The second line contains n integers f1, f2, ..., fn (1 ≤ fi ≤ n, fi ≠ i), meaning that the i-th plane likes the fi-th.

Output: Output «YES» if there is a love triangle consisting of planes on Earth. Otherwise, output «NO».

You can output any letter in lower case or in upper case.
*/

int main(){
    // retrieve number of planes
    int numPlanes;
    cin >> numPlanes;

    // declare a vector of size numPlanes + 1 (+1 for ease of indexing) to store which plane each plane (index) is connected to
    vector<int> planeConnection(numPlanes+1);
    for(int planeNum = 1; planeNum <= numPlanes; planeNum++){
        int connectedPlane;
        cin >> connectedPlane;
        planeConnection[planeNum] = connectedPlane;
    }

    // now loop through that vector and check if a triangle can be formed
    for(int planeNum = 1; planeNum <= numPlanes; planeNum++){
        // check if we can reach starting plane after passing through 2 other planes
        if(planeNum == planeConnection[planeConnection[planeConnection[planeNum]]]){
            cout << "YES" << endl;
            return 0;
        }
    }

    // if no triangle can be formed, print "NO"
    cout << "NO" << endl;
    return 0;
}