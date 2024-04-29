#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Closest Points
You are given a list of 𝑛 points 0≤𝑥𝑖,𝑦𝑖≤100000, where 𝑛≤50000. What is the distance between the closest two points?

Input: An integer n followed by n lines of two integers, representing the x and y coordinates of the points.

Output: A floating point number showing the distance between the two closest points.
*/

int main(){
    ll numPoints;
    cin >> numPoints;

    // initialize a vector to store the coordinate points then we sort by x in increasing order
    vector< pair<ll, ll> > coordinates;
    for(ll point = 0; point < numPoints; point++){
        ll x, y;
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }
    sort(coordinates.begin(), coordinates.end());

    // set the closest distance to a large number
    double closestDistance = 1e15;

    // cycle through all points and find the shortest distance/distance between the two closest points
    for(ll currentPoint = 0; currentPoint < numPoints; currentPoint++){
        // check all points q where xq - xp <= closestDistance and absolute value(yq - yp) <= closestDistance where p is the current point and q is possibleNextPoint
        ll possibleNextPoint = currentPoint+1;
        // move check for y coordinate difference to be within closestDistance inside while loop to make sure possibleNextPoint is updated
        // (avoid scenario where we have a point really close in x but really far in y, then we end up skipping remaining checks for subsequent possibleNextPoints)
        while(possibleNextPoint < numPoints && (coordinates[possibleNextPoint].first - coordinates[currentPoint].first) < closestDistance){
            if(abs(coordinates[possibleNextPoint].second - coordinates[currentPoint].second) < closestDistance){
                double potentialCloserDistance = sqrt(((coordinates[possibleNextPoint].first - coordinates[currentPoint].first) * (coordinates[possibleNextPoint].first - coordinates[currentPoint].first)) + ((coordinates[possibleNextPoint].second - coordinates[currentPoint].second) * (coordinates[possibleNextPoint].second - coordinates[currentPoint].second)));
                if(potentialCloserDistance < closestDistance){
                    closestDistance = potentialCloserDistance;
                }
            }
            possibleNextPoint++;
        }
    }

    cout << closestDistance << endl;
}