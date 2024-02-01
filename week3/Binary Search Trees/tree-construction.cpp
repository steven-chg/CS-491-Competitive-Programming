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
template <typename T>
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
template <typename T>
binarySearchTree<T>* addNode(binarySearchTree<T>* root, T value){
    bool notYetInserted = true;
    while(notYetInserted){
        // check current node value to see if we should go left or right
        if(root->value < value){
            // check if right child exists, if not, then insert here
            if(root->right == NULL){
                root->right = new binarySearchTree<T>(value);
                notYetInserted = false;
            } else{
            // if right child exists, then we move to the right child
                root = root->right;
            }
        } else{
            // check if left child exists, if not, then insert here
            if(root->left == NULL){
                root->left = new binarySearchTree<T>(value);
                notYetInserted = false;
            } else{
            // if left child exists, then we move to the left child
                root = root->left;
            }
        }
    }
    // return the parent pointer
    return root;
}

/* FIRST OPTIMIZATION; Store pointer to biggest and smallest value nodes; pass pointers to those nodes to add new nodes with values bigger or smaller, respectively */
int main(){
    // retrieve the length of the sequence 
    int sequenceLength;
    cin >> sequenceLength;

    // create the root node 
    long long int rootNodeValue;
    cin >> rootNodeValue;
    binarySearchTree<long long int> rootNode = binarySearchTree<long long int>(rootNodeValue);

    // FIRST OPTIMIZATION, declare pointers to the greatest and smallest value node and initialize them to point to root node
    binarySearchTree<long long int> *smallestNode = &rootNode;
    binarySearchTree<long long int> *biggestNode = &rootNode;

    // loop for the remaining n - 1 elements and add them to the tree 
    for(int elementNum = 2; elementNum <= sequenceLength; elementNum++){
        // retrieve the next value
        long long int newValue;
        cin >> newValue;

        // declare a pointer to store pointer to parent node of the newly created node
        binarySearchTree<long long int> *parentPointer;

        // FIRST OPTIMIZATION, check if new value is smaller than the smallest value node or greater than the greatest value node
        if(newValue > biggestNode->value){
            parentPointer = addNode(biggestNode, newValue);
            biggestNode = parentPointer->right;
        } else if(newValue < smallestNode->value){
            parentPointer = addNode(smallestNode, newValue);
            smallestNode = parentPointer->left;
        } else{
            parentPointer = addNode(&rootNode, newValue);
        }

        // print the value of the parent
        printf("%lld ", parentPointer->value);
    }

    printf("\n");
}

// /* NON OPTIMIZED BASE CODE */
// int main(){
//     // retrieve the length of the sequence 
//     int sequenceLength;
//     cin >> sequenceLength;

//     // create the root node 
//     long long int rootNodeValue;
//     cin >> rootNodeValue;
//     binarySearchTree<long long int> rootNode = binarySearchTree<long long int>(rootNodeValue);

//     /* DO NOT NEED TO STORE; JUST PRINT DIRECTLY */
//     // // declare a vector to store parent node values
//     // vector<long long int> parentNodeValues;

//     // loop for the remaining n - 1 elements and add them to the tree 
//     for(int elementNum = 2; elementNum <= sequenceLength; elementNum++){
//         // retrieve the next value
//         long long int newValue;
//         cin >> newValue;

//         // declare a pointer to store pointer to parent node of the newly created node
//         binarySearchTree<long long int> *parentPointer;
//         parentPointer = addNode(&rootNode, newValue);           // pass by pointer

//         /* REPLACED STORING INTO VECTOR */
//         // print the value of the parent
//         printf("%lld ", parentPointer->value);

//         /* DO NOT NEED TO STORE; JUST PRINT DIRECTLY */
//         // // retrieve parent node value and store it into vector
//         // parentNodeValues.push_back(parentPointer->value);
//     }

//     /* DO NOT NEED TO STORE; JUST PRINT DIRECTLY */
//     // // loop through the parent node value vector and print out the values
//     // for(int parentNum = 2; parentNum <= sequenceLength; parentNum++){
//     //     printf("%lld ", parentNodeValues[parentNum - 2]);
//     // }

//     printf("\n");
// }