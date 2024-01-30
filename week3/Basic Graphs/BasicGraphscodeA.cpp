#include <bits/stdc++.h>

using namespace std;

/* Network Topology
This problem uses a simplified network topology model, please read the problem statement carefully and use it as a f
ormal document as you develop the solution.

Polycarpus continues working as a system administrator in a large corporation. 
The computer network of this corporation consists of n computers, some of them are connected by a cable. 
The computers are indexed by integers from 1 to n. It's known that any two computers connected by cable directly or 
through other computers

Polycarpus decided to find out the network's topology. 
A network topology is the way of describing the network configuration, the scheme that shows the location and the 
connections of network devices.

Polycarpus knows three main network topologies: bus, ring and star. 
A bus is the topology that represents a shared cable with all computers connected with it. 
In the ring topology the cable connects each computer only with two other ones. A star is the topology where 
all computers of a network are connected to the single central node.

Let's represent each of these network topologies as a connected non-directed graph. 
A bus is a connected graph that is the only path, that is, the graph where all nodes are connected with two other ones 
except for some two nodes that are the beginning and the end of the path. A ring is a connected graph, where all nodes are 
connected with two other ones. A star is a connected graph, where a single central node is singled out and connected with all other nodes. 
For clarifications, see the picture.

You've got a connected non-directed graph that characterizes the computer network in Polycarpus' corporation. 
Help him find out, which topology type the given network is. If that is impossible to do, say that the network's topology is unknown.

Input: The first line contains two space-separated integers n and m (4 ≤ n ≤ 10^5; 3 ≤ m ≤ 10^5) — 
the number of nodes and edges in the graph, correspondingly. Next m lines contain the description of the graph's edges. 
The i-th line contains a space-separated pair of integers xi, yi (1 ≤ xi, yi ≤ n) — the numbers of nodes that are connected by 
the i-the edge.

It is guaranteed that the given graph is connected. 
There is at most one edge between any two nodes. No edge connects a node with itself.

Output: In a single line print the network topology name of the given graph. 
If the answer is the bus, print "bus topology" (without the quotes), 
if the answer is the ring, print "ring topology" (without the quotes), 
if the answer is the star, print "star topology" (without the quotes). 
If no answer fits, print "unknown topology" (without the quotes).
*/

int main(){

    /* Topology Traits */
    // Bus: All nodes connected with 2 other nodes, except 2 nodes connected to 1 other node
    // Ring: All nodes connected with 2 other nodes; # nodes = # of edges
    // Star: All nodes connected with the same singular node, which connects with all other nodes

    // retrieve number of nodes and number of edges
    long long int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    // declare a 2D vector to store the node #'s that each node is connected to; numNodes + 1 in 'row' dimension (+1 for ease of index)
    vector< vector<long long int> > adjacencyMatrix(numNodes + 1);

    // retrieve the edges and insert them into the corresponding vector
    long long int nodeOne, nodeTwo;
    for(int edgeNum = 0; edgeNum < numEdges; edgeNum++){
        cin >> nodeOne >> nodeTwo;
        adjacencyMatrix[nodeOne].push_back(nodeTwo);
        // since the graph is undirected
        adjacencyMatrix[nodeTwo].push_back(nodeOne);
    }

    // determine topology
    if(numNodes == numEdges){
        // could be a ring or unknown topology; check by going through all nodes and making sure the size of the vector is exactly 2
        bool ring = true;

        for(int nodeNum = 1; nodeNum <= numNodes; nodeNum++){
            if(adjacencyMatrix[nodeNum].size() != 2){
                // if any of the sizes of vectors for each node is not 2, then it is not a ring topology
                ring = false;
            }
        }

        if(ring){
            cout << "ring topology" << endl;
        } else{
            cout << "unknown topology" << endl;
        }

    } else if(numNodes ==(numEdges + 1)){
        // could be bus or star topology

        // declare and initialize variables for checking number of nodes connected to 2 other nodes and number connected to 1 other node and maximum connections any node has
        long int numConnectedTwo = 0; long int numConnectedOne = 0; long int mostConnections = 0;

        for(int nodeNum = 1; nodeNum <= numNodes; nodeNum++){
            // check for nodes connected to 1 other node
            if(adjacencyMatrix[nodeNum].size() == 1){
                numConnectedOne++;
                if(mostConnections < 1) mostConnections = adjacencyMatrix[nodeNum].size();
            } else if(adjacencyMatrix[nodeNum].size() == 2){
            // check for nodes connected to 2 other nodes
                numConnectedTwo++;
                if(mostConnections < 2) mostConnections = adjacencyMatrix[nodeNum].size();
            } else{
            // check for nodes connected to more than 2 other nodes (cannot be 0 since graph is connected)
                mostConnections = adjacencyMatrix[nodeNum].size();
            }
        }

        // check for bus topology
        if((numConnectedTwo == (numNodes - 2)) && (numConnectedOne == 2)){
            cout << "bus topology" << endl;
        } else if(numConnectedOne == (numNodes - 1) && mostConnections == (numNodes - 1)){
        // check for star topology
            cout << "star topology" << endl;
        } else{
            cout << "unknown topology" << endl;
        }
    } else{
        // unknown topology 
        cout << "unknown topology" << endl;
    }
    
}