#include <bits/stdc++.h>

using namespace std;

/* Tree Infection
A tree is a connected graph without cycles. A rooted tree has a special vertex called the root. The parent of a vertex v (different from root) 
is the previous to 𝑣 vertex on the shortest path from the root to the vertex 𝑣. Children of the vertex 𝑣 are all vertices for which 𝑣 is the parent.

You are given a rooted tree with 𝑛 vertices. The vertex 1 is the root. Initially, all vertices are healthy.
Each second you do two operations, the spreading operation and, after that, the injection operation:
    Spreading: for each vertex 𝑣, if at least one child of 𝑣 is infected, you can spread the disease by infecting at most one other child of 𝑣 of your choice.
    Injection: you can choose any healthy vertex and infect it.
This process repeats each second until the whole tree is infected. You need to find the minimal number of seconds needed to infect the whole tree.

Input: The input consists of multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤10^4) — the number of test cases. 
Description of the test cases follows.
    The first line of each test case contains a single integer 𝑛 (2≤𝑛≤2⋅10^5) — the number of the vertices in the given tree.
    The second line of each test case contains 𝑛−1 integers 𝑝2,𝑝3,…,𝑝𝑛 (1≤𝑝𝑖≤𝑛), where 𝑝𝑖 is the ancestor of the 𝑖-th vertex in the tree.

It is guaranteed that the given graph is a tree.
It is guaranteed that the sum of 𝑛 over all test cases doesn't exceed 2⋅10^5.

Output: For each test case you should output a single integer — the minimal number of seconds needed to infect the whole tree.
*/

int main(){

    /* Notes:
    - To infect the entire tree the fastest, infect nodes with the most siblings first
    - In other words, we need to first figure out how many parents there are in the tree and how many children each parent has
    - After we find all 'sibling sets' and the number of siblings in each set, assume that we perform infection operation once on each sibling set 
    - If there are still healthy nodes left after time = # of sibling sets, then we need to perform more spreading + infection operations (continue until no healthy nodes left)
    - First spread, then if needed, infect, (incrementing time) then loop and check again 
    */
    
    // retrieve number of test cases
    int numCases;
    scanf("%d", &numCases);

    // loop for number of test cases
    while(numCases){
        // retrieve number of vertices of each tree
        int numVertices;
        scanf("%d", &numVertices);

        // declare a vector of size numVertices + 1 (initialized to 0) that stores the number of children for each vertex (index will be vertex number)
        vector<int> numChildren(numVertices + 1, 0);
        // root node is children of index 0
        numChildren[0] = 1;

        // loop for numVertices - 1 times to get the parent of each node
        for(int i = 0; i < (numVertices - 1); i++){
            int parent;
            cin >> parent;
            // increment number of children the parent has 
            numChildren[parent]++;
        }

        // sort the vector in descending order
        sort(numChildren.begin(), numChildren.end(), greater<int>());

        // get rid of trailing 0s
        while(!numChildren.empty() && numChildren.back() == 0){
            numChildren.pop_back();
        }

        // first perform infect operation once on each set of siblings
        int minimumTime = numChildren.size();
        for(int infectOperation = 0; infectOperation < minimumTime; infectOperation++){
            if(numChildren[infectOperation] - minimumTime + infectOperation){
                numChildren[infectOperation] -= (minimumTime - infectOperation);
            } else{
                numChildren[infectOperation] = 0;
            }
        }

        // at this point, the vector contains the number of healthy nodes left after we infect each sibling set one single time and let minimumTime pass

        // loop until we break out
        while(1){

            // go through the entire vector and if all elements are 0, then we are done
            bool allZero = true;
            for(int i = 0; i < numChildren.size(); i++){
                if(numChildren[i] > 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero){
                break;
            }

            // otherwise, we need to repeat infection on an already infected set of siblings 
            
            // sort the vector in descending order again
            sort(numChildren.begin(), numChildren.end(), greater<int>());

            // now, let's increment minimumTime and perform the spreading operation again, and another infecting operation if needed
            minimumTime++;

            // perform spreading operation
            for(int i = 0; i < numChildren.size(); i++){
                if(numChildren[i] > 0){
                    numChildren[i]--;
                }
            }

            // perform injecting operation if needed
            if(numChildren[0] > 0){
                numChildren[0]--;
            }

        }

        // print the minimum time needed
        printf("%d\n", minimumTime);

        numCases--;
    }
}



