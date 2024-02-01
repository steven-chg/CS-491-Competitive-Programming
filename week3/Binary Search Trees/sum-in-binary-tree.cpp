#include <bits/stdc++.h>

using namespace std;

/* Sum In Binary Tree
Vanya really likes math. One day when he was solving another math problem, he came up with an interesting tree. This tree is built as follows.

Initially, the tree has only one vertex with the number 1 — the root of the tree. 
Then, Vanya adds two children to it, assigning them consecutive numbers — 2 and 3, respectively. 
After that, he will add children to the vertices in increasing order of their numbers, starting from 2, assigning their children 
the minimum unused indices. As a result, Vanya will have an infinite tree with the root in the vertex 1, where each vertex will 
have exactly two children, and the vertex numbers will be arranged sequentially by layers.

Vanya wondered what the sum of the vertex numbers on the path from the vertex with number 1 to the vertex with number 𝑛 in such a tree is equal to. 
Since Vanya doesn't like counting, he asked you to help him find this sum.

Input: The first line contains a single integer t (1≤𝑡≤10^4) — the number of test cases.
This is followed by 𝑡 lines — the description of the test cases. Each line contains one integer 𝑛 (1≤𝑛≤10^16) — the number of vertex for 
which Vanya wants to count the sum of vertex numbers on the path from the root to that vertex.

Output: For each test case, print one integer — the desired sum.
*/

int main(){
    // retrieve number of test cases
    int testCases;
    scanf("%d", &testCases);
    
    // loop for number of test cases
    while(testCases){
        // retrieve the desired vertex in current case
        long long int desiredVertex;
        scanf("%lld", &desiredVertex);

        // initialize a running sum to 0
        long long int runningSum = 0;

        // note a characteristic of this tree: to get to parent node, we just divide the value of current node by 2 (floor it)
        while(desiredVertex > 1){
            runningSum += desiredVertex;
            desiredVertex /= 2;
        }

        // add the root node
        runningSum += 1;

        printf("%lld\n", runningSum);

        testCases--;
    }
}