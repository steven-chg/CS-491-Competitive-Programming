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




}



