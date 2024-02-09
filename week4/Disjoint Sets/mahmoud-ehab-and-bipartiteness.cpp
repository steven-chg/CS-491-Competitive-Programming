#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Mahmoud and Ehab and the Bipartiteness
Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.
A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, 
that for each edge (u, v) that belongs to the graph, u and v belong to different sets. You can find more formal definitions of a tree and a 
bipartite graph in the notes section below.

Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite. 
Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges 
they can add?

A loop is an edge, which connects a node with itself. Graph doesn't contain multiple edges when for each pair of nodes there is no more than 
one edge between them. A cycle and a loop aren't the same .

Input: The first line of input contains an integer n — the number of nodes in the tree (1 ≤ n ≤ 10^5).
The next n - 1 lines contain integers u and v (1 ≤ u, v ≤ n, u ≠ v) — the description of the edges of the tree.
It's guaranteed that the given graph is a tree.

Output: Output one integer — the maximum number of edges that Mahmoud and Ehab can add to the tree while fulfilling the conditions.
*/

// declare a 2D vector with 1e5 + 1 rows (maximum number of nodes + 1) where each row stores the index of other nodes that the current node is connected to
vector< vector<ll> > nodeConnected(1e5 + 1);

// declare a vector to store checked status of each node (initialize to false)
vector<bool> nodeVisited(1e5 + 1, false);

// declare variables to track number of connected components in each set (initialize to 0)
ll numSetOne = 0; 
ll numSetTwo = 0;

void depth_first_search(ll nodeToSearch, int setNum){
    // increment the appropriate set
    if(setNum == 1) numSetOne++;
    else numSetTwo++;

    // mark this node as visited
    nodeVisited[nodeToSearch] = true;

    // go through all neighbors of current node
    for(int neighbor = 0; neighbor < nodeConnected[nodeToSearch].size(); neighbor++){
        ll neighborNodeNum = nodeConnected[nodeToSearch][neighbor];
        if(nodeVisited[neighborNodeNum] == false){
            // search the neighbor if it hasn't been visited yet
            if(setNum == 1) depth_first_search(neighborNodeNum, 2);
            else depth_first_search(neighborNodeNum, 1);
        }
    }

}

int main(){

    /* Notes:
    - given we have m nodes in one set and n nodes in the other set, then the maximum number of edges we can have while maintaining
    bipartiteness is m*n number of edges
    - therefore, we have to find the number of nodes in each set, multiply them together, then subtract by the number of current edges
    - to do so, we will add an extra argument in our depth first search that tracks which set the current node is in
    - this will always alternate between search function invocations (i.e. if i start in one set and search into its neighbors, its neighbors 
    will be in the opposite set)
    */

    // retrieve the number of nodes in the tree
    ll numNodes;
    scanf("%lld", &numNodes);

    //loop through all the edges and store the connected nodes
    for(int edge = 0; edge < (numNodes - 1); edge++){
        ll nodeOne, nodeTwo;
        scanf("%lld %lld", &nodeOne, &nodeTwo);

        nodeConnected[nodeOne].push_back(nodeTwo);
        nodeConnected[nodeTwo].push_back(nodeOne);
    }

    // perform depth first search (only need to do it once since the graph being bipartite means all nodes are connected)
    depth_first_search(1, 1);       // start with the first node and assume that it is in set one

    // after the search, we will have the number of components in each set; multiply them together and subtract current number of edges
    ll numEdgesCanAdd = (numSetOne*numSetTwo) - (numNodes - 1);

    printf("%lld\n", numEdgesCanAdd);

}
