#include <bits/stdc++.h>

using namespace std;

/* Tree Construction
During the programming classes Vasya was assigned a difficult problem. However, he doesn't know how to code and was unable to 
find the solution in the Internet, so he asks you to help.

You are given a sequence 𝑎, consisting of 𝑛 distinct integers, that is used to construct the binary search tree. 
Below is the formal description of the construction process.

First element 𝑎1 becomes the root of the tree. Elements 𝑎2,𝑎3,…,𝑎𝑛 are added one by one. To add element 𝑎𝑖 one needs to traverse the 
tree starting from the root and using the following rules:
    1. The pointer to the current node is set to the root.
    2. If 𝑎𝑖 is greater than the value in the current node, then its right child becomes the current node.
    Otherwise, the left child of the current node becomes the new current node.
    3. If at some point there is no required child, the new node is created, it is assigned value 𝑎𝑖 and becomes the corresponding 
    child of the current node.

Input: The first line of the input contains a single integer 𝑛 (2≤𝑛≤100000) — the length of the sequence 𝑎.
The second line contains 𝑛 distinct integers 𝑎𝑖 (1≤𝑎𝑖≤109) — the sequence 𝑎 itself.

Output: Output 𝑛−1 integers. For all 𝑖>1 print the value written in the node that is the parent of the node with value 𝑎𝑖 in it.
*/

// define binary search tree struct
template<typename T>
struct binarySearchTree{
    T value;
    binarySearchTree<T> *left, *right;

    // node constructor
    binarySearchTree<T>(T value) {
        this->value = value;
        left= right= NULL;
    }
};

// function for adding a new node to the tree
template<typename T>
void addNode(binarySearchTree<T>* root, long long int value){
    bool notYetInserted = true;
    while(notYetInserted)
        // check if right child exists and right child has value that is less than new value
        if(root->right != NULL && root->right->value < value){
            // go right
        else if(root->left != NULL && root->left->value > value){
        // check if the left child exists and left child has value that is greater than new value
        }
    }
}

template<typename T>
int main(){
    // retrieve the length of the sequence 
    int sequenceLength;
    cin >> sequenceLength;

    // create the root node 
    long long int rootNodeValue;
    cin >> rootNodeValue;
    binarySearchTree<T> rootNode = binarySearchTree<T>(rootNodeValue);

    // loop for the remaining n - 1 elements and add them to the tree 
    for(int elementNum = 1; elementNum < sequenceLength; elementNum++){
        long long int newValue;
        cin >> newValue;
        addNode(&rootPointer, newValue);    // pass by pointer
    }

    // at this point, rootPointer points to the root node of the entire tree that has finished construction




}