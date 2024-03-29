#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Longest Proper Suffix
For a string 𝑠 of length 𝑛, for all 𝑖=1,...𝑛, output the length of the longest proper suffix of 𝑠[0,...,𝑖] that matches a prefix of 𝑖. 
A proper suffix of a string is a suffix that is not equal to the string itself.

For example, if 𝑠 is 𝙰𝙱𝙳𝙰𝙱𝙲𝙰𝙱, and 𝑖=5, then 𝑠[0,...,𝑖]=𝙰𝙱𝙳𝙰𝙱. the longest proper suffix of 𝙰𝙱𝙳𝙰𝙱 that is a prefix of 𝑠 is 𝙰𝙱 which has length 2.

This is exactly the prefix table generated by the Knuth–Morris–Pratt algorithm.

Input: The first line contains 𝑠. 𝑠 consist only of capital Latin letters, and 1≤|𝑠|≤300000.

Output: Output on one line, for each 𝑖=1,...|𝑠|, the longest proper suffix of 𝑠[1,...,𝑖] that is a prefix of 𝑠.
*/

/* PREFIX FUNCTION */
int main(){
    string s;
    cin >> s;

    /* Notes:
    - when moving to the next position, the length of the longest proper suffix of the prefix can either increase by one, stay the same, or decrease by some amount. 
    */

    // declare a vector to store the length of longest proper suffix of a prefix of s of length-1 given by index, that also matches a prefix of s
    vector<ll> longest_length(s.size());
    // if prefix is length 1, then no proper suffix is possible, so initialize to 0
    longest_length[0] = 0;
    cout << longest_length[0] << " ";

    // loop through all other length prefixes
    for(ll i = 1; i < s.size(); i++){
        // find the length of the longest proper suffix with prefix of length given by previous index
        ll z = longest_length[i-1];

        while(z > 0 && s[z] != s[i]){
            z = longest_length[z-1];
        }

        if(s[z] == s[i]){
            longest_length[i] = z + 1;
        } else{
            longest_length[i] = 0;
        }

        cout << longest_length[i] << " ";
    }
    cout << endl;
}

/* TIME LIMIT EXCEEDED; NEED TO UPDATE HOW WE INCREMENT AND LOOK AT THE NEXT PROPER SUFFIX */
// int main(){
//     string s;
//     cin >> s;

//     for(ll i = 1; i <= s.size(); i++){
//         ll longest_propSuffix_len = 0;

//         // initialize an index pointing to the front of s
//         ll frontIndex = 0;
//         // initialize an index pointing to the start of the proper suffix of the prefix
//         ll startIndex = 1;
//         // initialize a tempLength to track the length of the current proper suffix we are checking
//         ll tempLength = i-1;

//         // loop through all proper suffixes (starting with longest length proper suffix)
//         while(startIndex <= i-1){
//             ll tempStart = startIndex;

//             while(s[frontIndex] == s[tempStart]){
//                 if(tempStart == i-1){
//                     longest_propSuffix_len = tempLength;
//                     break;
//                 }
//                 frontIndex++;
//                 tempStart++;
//             }

//             // if longest_propSuffix_len is greater than 0, we have found the longest length proper suffix
//             if(longest_propSuffix_len) break;

//             // if the current proper suffix isn't valid, increment startIndex (look at next longest proper suffix); also reset frontIndex to 0
//             frontIndex = 0;
//             startIndex++;
//             tempLength--;
//         }

//         cout << longest_propSuffix_len << " ";
//     }
//     cout << endl;
// }