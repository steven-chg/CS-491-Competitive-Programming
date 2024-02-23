#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Minimum Spanning Tree for Each Edge
Connected undirected weighted graph without self-loops and multiple edges is given. Graph contains n vertices and m edges.
For each edge (u, v) find the minimal possible weight of the spanning tree that contains the edge (u, v).
The weight of the spanning tree is the sum of weights of all edges included in spanning tree.

Input: First line contains two integers n and m (1 ≤ n ≤ 2·10^5, n - 1 ≤ m ≤ 2·10^5) — the number of vertices and edges in graph.

Each of the next m lines contains three integers ui, vi, wi (1 ≤ ui, vi ≤ n, ui ≠ vi, 1 ≤ wi ≤ 10^9) — the endpoints of the i-th edge and its weight.

Output: Print m lines. i-th line should contain the minimal possible weight of the spanning tree that contains i-th edge.
The edges are numbered from 1 to m in order of their appearing in input.
*/

/* TEST CASE 6 FAIL */
int main(){
    // retrieve number of vertices and edges
    ll numVertices, numEdges;
    scanf("%lld %lld", &numVertices, &numEdges);

    // create a vector storing the weight and the (u, v) vertices; and another vector that will store unsorted edges
    vector< pair<ll, pair<ll, ll> > > edgeList;
    vector< pair<ll, pair<ll, ll> > > unsortedEdge;
    for(int i = 0; i < numEdges; i++){
        ll u, v, weight;
        cin >> u >> v >> weight;
        unsortedEdge.push_back(make_pair(weight, make_pair(u, v)));
        edgeList.push_back(make_pair(weight, make_pair(u, v)));
    }

    /* SANITY CHECK; unsortedEdge and edgeList contains what we desire */
    // for(int i = 0; i < numEdges; i++){
    //     cout << unsortedEdge[i].first << unsortedEdge[i].second.first << unsortedEdge[i].second.second << endl;
    //     cout << edgeList[i].first << edgeList[i].second.first << edgeList[i].second.second << endl;
    // }

    /* at this point, edgeList contains all weights and edges */

    // perform Kruscal's algorithm to find MST 
    // declare a set to track which edges are in the original MST
    set<pair<ll, ll> > mstEdge;
    // declare a set to track the vertices in the MST
    set<ll> mstVertices;
    // sort the edgeList by weight (smallest weight to highest weight)
    sort(edgeList.begin(), edgeList.end());

    /* SANITY CHECK; edgeList contains what we desire after sort */
    // for(int i = 0; i < numEdges; i++){
    //     cout << edgeList[i].first << edgeList[i].second.first << edgeList[i].second.second << endl;
    // }

    ll minimumSpanningCost = 0;
    for(int i = 0; i < numEdges; i++){
        // retrieve the next edge
        pair<ll, pair<ll, ll> > front = edgeList[i];
        ll u = front.second.first;
        ll v = front.second.second;
        ll weight = front.first;

        // if at least 1 of the vertices isn't in the MST set; or the number of edges we've added to our MST is less than numVertices - 1
        if(mstVertices.find(u) == mstVertices.end() || mstVertices.find(v) == mstVertices.end() || (mstVertices.size() == numVertices && (mstEdge.size() < numVertices - 1))){

            /* SANITY CHECK: check which edges are part of the original MST (u, v) */
            // cout << u << ' ' << v << ' ' << endl;

            // add them to be part of the MST
            minimumSpanningCost += weight;
            mstEdge.insert(make_pair(u, v));

            // insert the vertices into the mstVertices set
            mstVertices.insert(u);
            mstVertices.insert(v);
        }
    }

    // loop through every edge and find the MST cost containing the edge
    for(int i = 0; i < numEdges; i++){
        pair<ll, ll> currentEdge = unsortedEdge[i].second;
        ll currentWeight = unsortedEdge[i].first;

        // check if this edge is already in the original MST, if so, then just print minimumSpanningCost
        if(mstEdge.find(currentEdge) != mstEdge.end()){
            cout << minimumSpanningCost << endl;
        } else{
            // if this edge isn't already in the original MST, perform Kruscal's algorithm with this edge already "chosen"
            ll newMinimumSpanningCost = currentWeight;
            set<ll> newMSTVertices;
            ll numEdgesIn = 1;
            ll u = currentEdge.first;
            ll v = currentEdge.second;

            /* CONFIRM THE EDGES THAT ENTER THIS CONDITION ARE CORRECT WITH newMinimumSpanningCost INITIALIZED CORRECTLY */
            // cout << u << ' ' << v << endl;
            // cout << newMinimumSpanningCost << endl;

            // insert the two vertices into the new MST set
            newMSTVertices.insert(u);
            newMSTVertices.insert(v);

            // go through all other edges, and skip this edge when we come across it again 
            for(int j = 0; j < numEdges; j++){
                // retrieve the next edge
                pair<ll, ll> newEdge = edgeList[j].second;
                ll newCost = edgeList[j].first;
                ll u2 = newEdge.first;
                ll v2 = newEdge.second;

                // skip this edge since it's already added
                if(newEdge.first == u && newEdge.second == v){
                    continue;
                }
                
                if(newMSTVertices.find(newEdge.first) == newMSTVertices.end() || newMSTVertices.find(newEdge.second) == newMSTVertices.end() || (newMSTVertices.size() == numVertices && (numEdgesIn < numVertices - 1))){
                    // add them to be part of the MST
                    newMinimumSpanningCost += newCost;
                    newMSTVertices.insert(newEdge.first);
                    newMSTVertices.insert(newEdge.second);
                    numEdgesIn++;
                }
            }
            cout << newMinimumSpanningCost << endl;
        }
    }
}

/* DISJOINT SET APPROACH TIMES OUT */
// // declare a vector to model disjoint sets (size = maximum number of vertices + 1); initialize to all -1
// vector<ll> disjointSet(2e5+1, -1);

// // function to find the index of the root vertex of the set that the vertexToFind belongs to 
// ll find(ll vertexToFind){
//     // if the value of the vertex is negative, it means it is the root vertex of the group, so return the index
//     if(disjointSet[vertexToFind] < 0){
//         return vertexToFind;
//     } else{
//     // else, recursively search the current vertex's parent while also updating the parent of the current vertex to be the root vertex of the set
//         return disjointSet[vertexToFind] = find(disjointSet[vertexToFind]);
//     }
// }

// // function to 'connect' two vertices in a disjoint set; returns index of the root vertex of the newly unified/formed set
// ll addDisjointSet(ll valueOne, ll valueTwo){
//     ll rootVertexValueOne = find(valueOne);
//     ll rootVertexValueTwo = find(valueTwo);
//     // if the two vertices have the same root, it means they belong to the same set/group already, return their root index
//     if(rootVertexValueOne == rootVertexValueTwo) return rootVertexValueOne;
//     // otherwise, join the two groups (connect the root index of the smaller group to the root index of the larger group)
//     if(disjointSet[rootVertexValueOne] > disjointSet[rootVertexValueTwo]){
//         disjointSet[rootVertexValueTwo] += disjointSet[rootVertexValueOne];
//         disjointSet[rootVertexValueOne] = rootVertexValueTwo;
//         return rootVertexValueTwo;
//     } else{
//         disjointSet[rootVertexValueOne] += disjointSet[rootVertexValueTwo];
//         disjointSet[rootVertexValueTwo] = rootVertexValueOne;
//         return rootVertexValueOne;
//     }
// }

// int main(){
//     // retrieve number of vertices and edges
//     ll numVertices, numEdges;
//     scanf("%lld %lld", &numVertices, &numEdges);

//     // create a vector storing the weight and the (u, v) vertices; and another vector that will store unsorted edges
//     vector< pair<ll, pair<ll, ll> > > edgeList;
//     vector< pair<ll, pair<ll, ll> > > unsortedEdge;
//     for(int i = 0; i < numEdges; i++){
//         ll u, v, weight;
//         cin >> u >> v >> weight;
//         unsortedEdge.push_back(make_pair(weight, make_pair(u, v)));
//         edgeList.push_back(make_pair(weight, make_pair(u, v)));
//     }

//     /* SANITY CHECK; unsortedEdge and edgeList contains what we desire */
//     // for(int i = 0; i < numEdges; i++){
//     //     cout << unsortedEdge[i].first << unsortedEdge[i].second.first << unsortedEdge[i].second.second << endl;
//     //     cout << edgeList[i].first << edgeList[i].second.first << edgeList[i].second.second << endl;
//     // }

//     /* at this point, edgeList contains all weights and edges */

//     // perform Kruscal's algorithm to find MST 
//     // declare a set to track which edges are in the original MST
//     set<pair<ll, ll> > mstEdge;
//     // sort the edgeList by weight (smallest weight to highest weight)
//     sort(edgeList.begin(), edgeList.end());

//     /* SANITY CHECK; edgeList contains what we desire after sort */
//     // for(int i = 0; i < numEdges; i++){
//     //     cout << edgeList[i].first << edgeList[i].second.first << edgeList[i].second.second << endl;
//     // }

//     ll minimumSpanningCost = 0;
//     for(int i = 0; i < numEdges; i++){
//         // retrieve the next edge
//         pair<ll, pair<ll, ll> > front = edgeList[i];
//         ll u = front.second.first;
//         ll v = front.second.second;
//         ll weight = front.first;

//         // if the two vertices not already in the same set
//         if(find(u) != find(v)){
//             // add them to be part of the MST
//             minimumSpanningCost += weight;
//             addDisjointSet(u, v);
//             // also track which edges are already part of the MST
//             mstEdge.insert(make_pair(u, v));
//         }
//     }
    
//     // reset the disjoint set to -1
//     for(int i = 1; i <= numEdges; i++){
//         disjointSet[i] = -1;
//     }

//     // loop through every edge and find the MST cost containing the edge
//     for(int i = 0; i < numEdges; i++){
//         pair<ll, ll> currentEdge = unsortedEdge[i].second;
//         ll currentWeight = unsortedEdge[i].first;
//         // check if this edge is already in the original MST, if so, then just print minimumSpanningCost
//         if(mstEdge.find(currentEdge) != mstEdge.end()){
//             cout << minimumSpanningCost << endl;
//         } else{
//             // if this edge isn't already in the original MST, perform Kruscal's algorithm with this edge already "chosen"
//             ll newMinimumSpanningCost = currentWeight;
//             addDisjointSet(currentEdge.first, currentEdge.second);

//             // go through all other edges, and skip this edge when we come across it again 
//             for(int i = 0; i < numEdges; i++){
//                 // retrieve the next edge
//                 pair<ll, pair<ll, ll> > front = edgeList[i];
//                 // skip this edge since it's already added
//                 if(front.second.first == currentEdge.first && front.second.second == currentEdge.second) continue;

//                 // if the two vertices not already in the same set
//                 if(find(front.second.first) != find(front.second.second)){
//                     // add them to be part of the MST
//                     newMinimumSpanningCost += front.first;
//                     addDisjointSet(front.second.first, front.second.second);
//                 }
//             }

//             cout << newMinimumSpanningCost << endl;
            
//             // reset the disjoint set to -1
//             for(int i = 1; i <= numEdges; i++){
//                 disjointSet[i] = -1;
//             }
//         }
//     }
// }
