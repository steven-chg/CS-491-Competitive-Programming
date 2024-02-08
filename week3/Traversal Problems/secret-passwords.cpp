#include <bits/stdc++.h>

using namespace std;

/* Secret Passwords
One unknown hacker wants to get the admin's password of AtForces testing system, to get problems from the next contest. 
To achieve that, he sneaked into the administrator's office and stole a piece of paper with a list of 𝑛 passwords — strings, 
consists of small Latin letters.

Hacker went home and started preparing to hack AtForces. He found that the system contains only passwords from the stolen list and that the 
system determines the equivalence of the passwords 𝑎 and 𝑏 as follows:
    two passwords 𝑎 and 𝑏 are equivalent if there is a letter, that exists in both 𝑎 and 𝑏;
    two passwords 𝑎 and 𝑏 are equivalent if there is a password 𝑐 from the list, which is equivalent to both 𝑎 and 𝑏.

If a password is set in the system and an equivalent one is applied to access the system, then the user is accessed into the system.
For example, if the list contain passwords "a", "b", "ab", "d", then passwords "a", "b", "ab" are equivalent to each other, 
but the password "d" is not equivalent to any other password from list. In other words, if:
    admin's password is "b", then you can access to system by using any of this passwords: "a", "b", "ab";
    admin's password is "d", then you can access to system by using only "d".
Only one password from the list is the admin's password from the testing system. 
Help hacker to calculate the minimal number of passwords, required to guaranteed access to the system. 
Keep in mind that the hacker does not know which password is set in the system.

Input: The first line contain integer 𝑛 (1≤𝑛≤2⋅10^5) — number of passwords in the list. Next 𝑛 lines contains passwords from the list 
– non-empty strings 𝑠𝑖, with length at most 50 letters. Some of the passwords may be equal.

It is guaranteed that the total length of all passwords does not exceed 10^6 letters. All of them consist only of lowercase Latin letters.

Output: In a single line print the minimal number of passwords, the use of which will allow guaranteed to access the system.
*/

/* declare a 2D vector to store all password and letter nodes in the tree
1. first numPasswords vectors each store the indices of letters that appear in the password (i.e. passwordAndLetterNodes[0] = {numPasswords, numPasswords+1} means 
first password includes both letters 'a' and 'b', as the index numPasswords into passwordAndLetterNodes returns the vector that stores indices of all passwords 
containing the letter 'a')
2. on the other hand, if passwordAndLetterNodes[numPasswords] = {0, 1}, then it means the letter 'a' appears in the first 2 passwords
*/
vector< vector<long long int> > passwordAndLetterNodes(2e5 + 26);       // maximum of 2e5 passwords + 26 letters in the alphabet

// declare a vector to track which nodes have been 'visited/covered' (initialize to false to indicate hasn't been visited/covered)
vector<bool> visitedNodes(2e5 + 26, false);

void depth_first_search(long long int nodeToSearch){

    /* to recursively 'visit/cover' a node, we need to 
    1. find what nodes it points to (what letters it includes)
    2. visit those nodes/letters
    */

    // loop through all nodes current node points to/all letters that current password includes
    long long int numNeighboringNodes = passwordAndLetterNodes[nodeToSearch].size();
    for(int nodes = 0; nodes < numNeighboringNodes; nodes++){
        // check if the node it points to has been visited, if not, mark it as visited and search into it
        long long int neighborIndex = passwordAndLetterNodes[nodeToSearch][nodes];
        if(visitedNodes[neighborIndex] == false){
            visitedNodes[neighborIndex] = true;
            depth_first_search(neighborIndex);
        }
    }

    // mark current node as visited
    visitedNodes[nodeToSearch] = true;

}

int main(){
    // retrieve number of passwords
    long long int numPasswords;
    cin >> numPasswords;

    // get all the passwords and for each password, connect the passwords to the letters and vice versa (through indices; 0 indexed)
    for(long long int password = 0; password < numPasswords; password++){
        // retrieve the current password
        string currentPassword;
        cin >> currentPassword;

        // loop through each character in the password
        for(int character = 0; character < currentPassword.size(); character++){
            // connected the password node to all the letter nodes
            passwordAndLetterNodes[password].push_back(currentPassword[character] - 'a' + numPasswords);
            // connect the letter to the password 
            passwordAndLetterNodes[currentPassword[character] - 'a' + numPasswords].push_back(password);
        }
    }

    // afterwards, go through and perform depth first search to find number of connected components
    long long int minimumTries = 0;

    for(long long int password = 0; password < numPasswords; password++){
        // if the password/letter has not been visited/covered, then we need to increment number of tries (connected components) and perform depth first search 
        if(visitedNodes[password] == false){
            // search the node and increment minimum passwords to try
            minimumTries++;
            depth_first_search(password);
        }
    }
    
    // find the minimum number of passwords (number of connected components) to guess
    cout << minimumTries << endl;

}

