#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Checkposts
Your city has n junctions. There are m one-way roads between the junctions. 
As a mayor of the city, you have to ensure the security of all the junctions.

To ensure the security, you have to build some police checkposts. 
Checkposts can only be built in a junction. A checkpost at junction i can protect junction j if either i = j or 
the police patrol car can go to j from i and then come back to i.

Building checkposts costs some money. As some areas of the city are more expensive than others, building checkpost at some 
junctions might cost more money than other junctions.

You have to determine the minimum possible money needed to ensure the security of all the junctions. 
Also you have to find the number of ways to ensure the security in minimum price and in addition in minimum number of checkposts. 
Two ways are different if any of the junctions contains a checkpost in one of them and do not contain in the other.

Input: In the first line, you will be given an integer n, number of junctions (1 ≤ n ≤ 10^5). In the next line, 
n space-separated integers will be given. The ith integer is the cost of building checkpost at the ith junction 
(costs will be non-negative and will not exceed 10^9).

The next line will contain an integer m (0 ≤ m ≤ 3·10^5). And each of the next m lines contains two integers ui and vi 
(1 ≤ ui, vi ≤ n; u ≠ v). A pair ui, vi means, that there is a one-way road which goes from ui to vi. 
There will not be more than one road between two nodes in the same direction.

Output: Print two integers separated by spaces. The first one is the minimum possible money needed to ensure the security of all the junctions. 
And the second one is the number of ways you can ensure the security modulo 1000000007 (10^9 + 7).
*/

int main(){
    /* Notes
    - Nodes will represent junctions
    - We need to be able to know if a node can visit another node and return to itself
    - Minimum Possible Money 
        - Find every path from each node to itself (and find the lowest cost of every single node in the path)
    - Number of ways to ensure security
        - For each junction, find every path from each node to itself (keep track of the number of nodes it passed
    */

    // retrieve number of junctions
    ll numJunctions;
    scanf("%lld", &numJunctions);

    // retrieve cost of building checkpost at each junction
    vector<ll> checkpostCost(numJunctions+1);
    for(int junctionNum = 1; junctionNum <= numJunctions; junctionNum++){
        ll cost;
        cin >> cost;
        checkpostCost[junctionNum] = cost;
    }


}