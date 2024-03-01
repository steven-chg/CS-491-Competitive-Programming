#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Canine Poetry
After his wife's tragic death, Eurydice, Orpheus descended to the realm of death to see her. 
Reaching its gates was uneasy, but passing through them proved to be even more challenging. 
Mostly because of Cerberus, the three-headed hound of Hades.

Orpheus, a famous poet, and musician plans to calm Cerberus with his poetry and safely walk past him. 
He created a very peculiar poem for Cerberus. It consists only of lowercase English letters.

We call a poem's substring a palindrome if and only if it reads the same backwards and forwards. A string 𝑎 is a substring of a string 𝑏
if 𝑎 can be obtained from 𝑏 by deleting several (possibly zero or all) characters from the beginning and several (possibly zero or all) 
characters from the end.

Unfortunately, Cerberus dislikes palindromes of length greater than 1. 
For example in the poem abaa the hound of Hades wouldn't like substrings aba and aa.

Orpheus can only calm Cerberus if the hound likes his poetry. 
That's why he wants to change his poem so that it does not contain any palindrome substrings of length greater than 1.

Orpheus can modify the poem by replacing a letter at any position with any lowercase English letter. 
He can use this operation arbitrarily many times (possibly zero). 
Since there can be many palindromes in his poem, he may have to make some corrections. 
But how many, exactly? Given the poem, determine the minimal number of letters that have to be changed so that the 
poem does not contain any palindromes of length greater than 1.

Input: The first line of the input contains a single integer 𝑡 (1≤𝑡≤10^5) denoting the number of test cases, then 𝑡 test cases follow.

The first and only line of each test case contains a non-empty string of lowercase English letters, Orpheus' poem.

The sum of the length of Orpheus' poems in all test cases will not exceed 10^5.

Output: You should output 𝑡 lines, 𝑖-th line should contain a single integer, answer to the 𝑖-th test case.
*/

int main(){
    ll numCases;
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        string s;
        cin >> s;

        /* Notes: 
        - we can loop through the entire string and check every letter and compare with its previous 2 letters 
        - if it is the same as the last letter or 2 letters before, then we need to change the current letter
        - ex: aba (1st and 2nd letter, and 2nd and 3rd letters are different, but the 3rd letter is the same as the 1st letter)
        - in that case, we can change it to a '!' symbol and increment the number of operations needed
        */

        ll numOperations = 0;

        // check the first 2 letters
        if(s.size() >= 2){
            if(s[0] == s[1]){
                numOperations++;
                s[1] = '!';             // need to change 2nd letter, cannot simply change first letter
            }
        }

        // loop through remainder of the string and check against 1 letter prior and 2 letters prior
        for(int i = 2; i < s.size(); i++){
            if(s[i-1] == s[i]){
                numOperations++;
                s[i] = '!';
            }

            // make sure to add another condition check to prevent case where !aa double counts after we change to !a! (skip this check if we already modified current letter)
            if(s[i-2] == s[i] && s[i] != '!'){
                numOperations++;
                s[i] = '!';
            }
        }

        cout << numOperations << endl;
    }

}