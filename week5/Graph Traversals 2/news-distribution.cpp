#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* News Distribution
In some social network, there are 𝑛 users communicating with each other in 𝑚 groups of friends. 
Let's analyze the process of distributing some news between users.

Initially, some user 𝑥 receives the news from some source. 
Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong 
to this group). Friends continue sending the news to their friends, and so on. 
The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.

For each user 𝑥 you have to determine what is the number of users that will know the news if initially only user 𝑥 starts distributing it.

Input: The first line contains two integers 𝑛 and 𝑚 (1≤𝑛,𝑚≤5⋅10^5) — the number of users and the number of groups of friends, respectively.

Then 𝑚 lines follow, each describing a group of friends. The 𝑖-th line begins with integer 𝑘𝑖 (0≤𝑘𝑖≤𝑛) — the number of users in the 𝑖-th group. 
Then 𝑘𝑖 distinct integers follow, denoting the users belonging to the 𝑖-th group.
It is guaranteed that ∑𝑖=1𝑚𝑘𝑖≤5⋅10^5.

Output: Print 𝑛 integers. The 𝑖-th integer should be equal to the number of users that will know the news if user 𝑖 starts distributing it.
*/

// declare a vector to model disjoint sets (size = maximum number of users + 1); initialize to all -1
vector<ll> disjointSet(5e5+1, -1);

// function to find the index of the root vertex of the group that the argument passed in (vertex index) belongs to
ll find(ll vertexToFind){
    // if the value of the vertex is negative, it means it is the root vertex of the group, so return the index
    if(disjointSet[vertexToFind] < 0){
        return vertexToFind;
    } else{
    // else, recursively search the current vertex's parent while also updating the parent of the current vertex to be the root vertex of the group
        return disjointSet[vertexToFind] = find(disjointSet[vertexToFind]);
    }
}

// function to 'connect' two vertices in a disjoint set; returns index of the root vertex of the newly unified/formed group
ll addDisjointSet(ll valueOne, ll valueTwo){
    ll rootVertexValueOne = find(valueOne);
    ll rootVertexValueTwo = find(valueTwo);
    // if the two vertices have the same root, it means they belong to the same set/group already, return their root index
    if(rootVertexValueOne == rootVertexValueTwo) return rootVertexValueOne;
    // otherwise, join the two groups (connect the root index of the smaller group to the root index of the larger group)
    if(disjointSet[rootVertexValueOne] > disjointSet[rootVertexValueTwo]){
        disjointSet[rootVertexValueTwo] += disjointSet[rootVertexValueOne];
        disjointSet[rootVertexValueOne] = rootVertexValueTwo;
        return rootVertexValueTwo;
    } else{
        disjointSet[rootVertexValueOne] += disjointSet[rootVertexValueTwo];
        disjointSet[rootVertexValueTwo] = rootVertexValueOne;
        return rootVertexValueOne;
    }
}

int main(){
    // retrieve the number of users (vertices) and the number of friend group
    ll numUsers, numFriendGroups;
    scanf("%lld %lld", &numUsers, &numFriendGroups);

    // go through all friend group
    for(int groupNum = 0; groupNum < numFriendGroups; groupNum++){
        // get the number of users in the group
        ll numUsersInGroup;
        scanf("%lld", &numUsersInGroup);

        // get every user in the group
        for(int userNum = 0; userNum < numUsersInGroup; userNum++){
            ll firstUser;
            ll secondUser;
            // set the first user as the first user in the pair (if only one user, then we don't need to perform addDisjointSet)
            if(userNum == 0){
                cin >> firstUser;
            // set every subsequent user as the second user in the pair and perform addDisjointSet to get them in the same group
            } else{
                cin >> secondUser;
                addDisjointSet(firstUser, secondUser);
            }
        }
    }

    // go through each user and see how many people this user can reach
    for(int userNum = 1; userNum <= numUsers; userNum++){
        // find the root index of the group the current user is in, then print the magnitude of the value stored at the root index (which will be number of people in the group)
        ll rootIndex = find(userNum);
        cout << abs(disjointSet[rootIndex]) << ' ';
    }
    cout << endl;
}