#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Greg and Path
Greg has a weighed directed graph, consisting of n vertices. In this graph any pair of distinct vertices has an edge between them in both directions. 
Greg loves playing with the graph and now he has invented a new game:
- The game consists of n steps.
- On the i-th step Greg removes vertex number xi from the graph. As Greg removes a vertex, he also removes all the edges that go in and out of this vertex.
- Before executing each step, Greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining vertices. 
The shortest path can go through any remaining vertex. In other words, if we assume that d(i, v, u) is the shortest path between vertices v and u 
in the graph that formed before deleting vertex xi, then Greg wants to know the value of the following sum:

Help Greg, print the value of the required sum before each step.

Input: The first line contains integer n (1 ≤ n ≤ 500) — the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: the j-th number in the i-th line aij (1 ≤ aij ≤ 10^5, aii = 0) represents the weight of the edge that 
goes from vertex i to vertex j.

The next line contains n distinct integers: x1, x2, ..., xn (1 ≤ xi ≤ n) — the vertices that Greg deletes.

Output: Print n integers — the i-th number equals the required sum before the i-th step.
Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.
*/

int main(){
    // retrieve the number of vertices in the graph
    int numVertices;
    scanf("%d", &numVertices);

    // declare a 2D vector to store edge weights (numVertices x numVertices)
    vector< vector<ll> > adjacencyMatrix(numVertices);

    // loop for numVertices times x numVertices times to get all the edge weights
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            // retrieve the edge weight and store in matrix (2D vector)
            ll edgeWeight;
            cin >> edgeWeight;
            adjacencyMatrix[i].push_back(edgeWeight);
        }
    }
    
    // at this point, adjacencyMatrix stores all edge weights between vertices

    // declare a vector to track all vertices that we need to 'skip' since we deleted it
    vector<bool> deleted(numVertices, false);
    // declare a vector to track order of vertex deletion
    vector<int> deletedVertex(numVertices);

    // declare vector to store shortest path lengths
    vector<ll> shortestPath(numVertices);

    // get all the deleted vertices; store them in reverse order (index 0 will store the last node deleted, and so on)
    for(int deletenum = (numVertices-1); deletenum >= 0; deletenum--){
        int vertexDeleted;
        cin >> vertexDeleted;
        // subtract 1 to make it 0 indexed 
        deleted[vertexDeleted - 1] = true;
        deletedVertex[deletenum] = vertexDeleted - 1;
    }

    // loop through deletions and slowly 'activate' vertices
    for(int deletionNum = 0; deletionNum < numVertices; deletionNum++){
        // get the next vertex to 'activate' (0 indexed) and 'undelete' it
        int vertexActivate = deletedVertex[deletionNum];
        deleted[vertexActivate] = false;

        // initiate running sum of shortest path with current 'active' vertices
        ll sumLengthShortestPath = 0;

        // find the shortest path matrix; Floyd Warshall algorithm
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                // update matrix by passing through this newly activated vertex
                adjacencyMatrix[i][j] = min(adjacencyMatrix[i][j], adjacencyMatrix[i][vertexActivate] + adjacencyMatrix[vertexActivate][j]);
                // if both i and j vertices are active, then we can add it to the running sum of shortest path length 
                if(deleted[i] == false && deleted[j] == false){
                    sumLengthShortestPath += adjacencyMatrix[i][j];
                }
            }
        }

        shortestPath[deletionNum] = sumLengthShortestPath;
    }

    // print out the shortest paths
    for(int i = (numVertices-1); i >= 0; i--){
        cout << shortestPath[i] << " ";
    }
    cout << endl;
}

// // OPTIMIZED BY REMOVING COPYING ADJACENCY MATRIX INTO A SHORTEST PATH MATRIX EVERY SINGLE DELETION; STILL EXCEEDS TIME LIMIT
// int main(){
//     // retrieve the number of vertices in the graph
//     int numVertices;
//     scanf("%d", &numVertices);

//     // declare a 2D vector to store edge weights (numVertices x numVertices)
//     vector< vector<ll> > adjacencyMatrix(numVertices);

//     // loop for numVertices times x numVertices times to get all the edge weights
//     for(int i = 0; i < numVertices; i++){
//         for(int j = 0; j < numVertices; j++){
//             // retrieve the edge weight and store in matrix (2D vector)
//             ll edgeWeight;
//             cin >> edgeWeight;
//             adjacencyMatrix[i].push_back(edgeWeight);
//         }
//     }
    
//     // at this point, adjacencyMatrix stores all edge weights between vertices

//     // declare a vector to track all vertices that we need to 'skip' since we deleted it
//     vector<bool> deleted(numVertices - 1, false);
//     vector<int> deletedVertex(numVertices - 1);

//     // declare vector to store shortest path lengths
//     vector<ll> shortestPath(numVertices);

//     // get all the deleted vertices; don't care about the last one 
//     for(int deletenum = 0; deletenum < numVertices; deletenum++){
//         int vertexDeleted;
//         cin >> vertexDeleted;
//         if(deletenum != numVertices-1){
//             deleted[vertexDeleted - 1] = true;
//             deletedVertex[deletenum] = vertexDeleted;
//         }
//     }

//     // loop through number of times that we need to print required sum (before each vertex deletion)
//     for(int deletionNum = 0; deletionNum < numVertices; deletionNum++){
//         // find the shortest path matrix; Floyd Warshall algorithm
//         for(int k = 0; k < numVertices; k++){
//             for(int i = 0; i < numVertices; i++){
//                 for(int j = 0; j < numVertices; j++){
//                     if(deleted[i] == false && deleted[j] == false && deleted[k] == false){
//                         adjacencyMatrix[i][j] = min(adjacencyMatrix[i][j], adjacencyMatrix[i][k] + adjacencyMatrix[k][j]);
//                     }
//                 }
//             }
//         }

//         // find required sum and print it 
//         ll sumLengthShortestPath = 0;
//         // loop through the entire 2D shortest path matrix
//         for(int vertexOne = 0; vertexOne < numVertices; vertexOne++){
//             for(int vertexTwo = 0; vertexTwo < numVertices; vertexTwo++){
//                 if(vertexOne != vertexTwo && deleted[vertexOne] == false && deleted[vertexTwo] == false) sumLengthShortestPath += adjacencyMatrix[vertexOne][vertexTwo];
//             }
//         }
//         shortestPath[deletionNum] = sumLengthShortestPath;

//         // updated deleted vector
//         if(deletionNum < numVertices - 1){
//             deleted[deletedVertex[(numVertices - deletionNum - 2)] - 1] = false;
//         }
//     }

//     // print out the shortest paths
//     for(int i = (numVertices-1); i >= 0; i--){
//         cout << shortestPath[i] << " ";
//     }
//     cout << endl;
// }

// // NON-OPTIMIZED; EXCEEDS TIME LIMIT
// int main(){
//     // retrieve the number of vertices in the graph
//     int numVertices;
//     scanf("%d", &numVertices);

//     // declare a 2D vector to store edge weights (numVertices x numVertices)
//     vector< vector<ll> > adjacencyMatrix(numVertices);

//     // loop for numVertices times x numVertices times to get all the edge weights
//     for(int i = 0; i < numVertices; i++){
//         for(int j = 0; j < numVertices; j++){
//             // retrieve the edge weight and store in matrix (2D vector)
//             ll edgeWeight;
//             cin >> edgeWeight;
//             adjacencyMatrix[i].push_back(edgeWeight);
//         }
//     }
    
//     // at this point, adjacencyMatrix stores all edge weights between vertices

//     // declare a vector to track all vertices that we need to 'skip' since we deleted it
//     vector<bool> deleted(numVertices, false);

//     // declare vector to store shortest path lengths
//     vector<ll> shortestPath(numVertices);

//     // loop through number of times that we need to print required sum (before each vertex deletion)
//     for(int deletionNum = 0; deletionNum < numVertices; deletionNum++){
//         // declare a new 2D vector that will contain new shortest path between vertices (decrement rows based on how many vertices deleted)
//         vector< vector<ll> > shortestPathMatrix(numVertices - deletionNum);       

//         int iShortest = 0; 
//         // copy edge weights into new shortest path vector
//         for(int i = 0; i < numVertices; i++){
//             for(int j = 0; j < numVertices; j++){
//                 if(deleted[i] == false && deleted[j] == false) shortestPathMatrix[iShortest].push_back(adjacencyMatrix[i][j]);
//             }
//             // only update the row index into shortestPathMatrix if the current row vertex isn't deleted
//             if(deleted[i] == false) iShortest++;
//         }

//         // find the shortest path matrix; Floyd Warshall algorithm
//         for(int k = 0; k < (numVertices - deletionNum); k++){
//             for(int i = 0; i < (numVertices - deletionNum); i++){
//                 for(int j = 0; j < (numVertices - deletionNum); j++){
//                     shortestPathMatrix[i][j] = min(shortestPathMatrix[i][j], shortestPathMatrix[i][k] + shortestPathMatrix[k][j]);
//                 }
//             }
//         }

//         // find required sum and print it 
//         ll sumLengthShortestPath = 0;
//         // loop through the entire 2D shortest path matrix
//         for(int vertexOne = 0; vertexOne < (numVertices - deletionNum); vertexOne++){
//             for(int vertexTwo = 0; vertexTwo < (numVertices - deletionNum); vertexTwo++){
//                 if(vertexOne != vertexTwo) sumLengthShortestPath += shortestPathMatrix[vertexOne][vertexTwo];
//             }
//         }
//         shortestPath[deletionNum] = sumLengthShortestPath;

//         // get the next vertex deleted and insert it into the set
//         int vertexDeleted;
//         cin >> vertexDeleted;
//         deleted[vertexDeleted - 1] = true;
//     }

//     // print out the shortest paths
//     for(int i = 0; i < numVertices; i++){
//         cout << shortestPath[i] << " ";
//     }
//     cout << endl;
// }