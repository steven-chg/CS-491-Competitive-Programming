#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Consecutive Subsequence
You are given an integer array of length 𝑛.

You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of 
consecutive integers. In other words the required sequence should be equal to [𝑥,𝑥+1,…,𝑥+𝑘−1] for some value 𝑥 and length 𝑘.

Subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. You can erase any elements, 
not necessarily going successively. The remaining elements preserve their order. For example, for the array [5,3,1,2,4] the following 
arrays are subsequences: [3], [5,3,1,2,4], [5,1,4], but the array [1,3] is not.

Input: The first line of the input containing integer number 𝑛 (1≤𝑛≤2⋅10^5) — the length of the array. 

The second line of the input containing 𝑛 integer numbers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10^9) — the array itself.

Output: On the first line print 𝑘 — the maximum length of the subsequence of the given array that forms an increasing sequence of 
consecutive integers.

On the second line print the sequence of the indices of the any maximum length subsequence of the given array that forms an 
increasing sequence of consecutive integers.
*/


/* DOES NOT ACCOUNT FOR ARRAYS LIKE 2 1 1 1 1 2 */
// int main(){
//     ll arrayLength;
//     cin >> arrayLength;

//     /* Notes:
//     - we want to store both the original index and the value
//     - sort by the value 
//     - go through the entire vector and find the longest consecutive subsequence 
//     */

//     // store both the value and the original index position of the value in a vector
//     set<ll> appearedValue;
//     vector< pair<ll, ll> > array(arrayLength + 1);

//     for(int i = 1; i <= arrayLength; i++){
//         cin >> array[i].first;
//         array[i].second = i;
//     }

//     // sort in ascending order by the value of the array
//     sort(array.begin(), array.end());

//     // for(int i = 1; i <= arrayLength; i++){
//     //     cout << array[i].first;
//     // }

//     ll maxLengthSubsequence = 1;
//     ll indexStartMaxSubsequence;
//     ll indexStartLocalSubsequence;

//     ll previousVal = -1;
//     ll previousIndex = -1;
//     ll localMaxLength = 0;
//     vector<ll> localConsecutiveSubsequence;

//     for(int i = 1; i <= arrayLength; i++){
//         // working on the first value in the array
//         if(previousVal == -1){
//             previousVal = array[i].first;
//             previousIndex = array[i].second;
//             localMaxLength++;
//             indexStartLocalSubsequence = 1;
//             indexStartMaxSubsequence = 1;

//         } else{
//             // this next value isn't a part of the subsequence, 
//             if((array[i].first != previousVal + 1) || (previousIndex > array[i].second)){
//                 // BUT it is possible that a value(s) further down the line is a part of the subsequence
//                 // we need to continue checking until we reach a value that ISN'T equal to the previous value 
//                 for(int j = i; j <= arrayLength; j++){
                    
//                 }


//                 // update the maxLengthSubsequence if appropriate 
//                 if(localMaxLength > maxLengthSubsequence){
//                     maxLengthSubsequence = localMaxLength;
//                     indexStartMaxSubsequence = indexStartLocalSubsequence;
//                 } 
//                 // reset localMaxLength to 1
//                 localMaxLength = 1;
//                 previousVal = array[i].first;
//                 previousIndex = array[i].second;
//                 indexStartLocalSubsequence = i;

//             } else{
//                 // this next value also belongs in the subsequence
//                 previousVal = array[i].first;
//                 previousIndex = array[i].second;
//                 localMaxLength++;
//             }
//         }
//     }

//     if(localMaxLength > maxLengthSubsequence){
//         maxLengthSubsequence = localMaxLength;
//         indexStartMaxSubsequence = indexStartLocalSubsequence;
//     }

//     cout << maxLengthSubsequence << endl;

//     for(int i = 0; i < maxLengthSubsequence; i++){
//         cout << array[indexStartMaxSubsequence].second << " ";
//         indexStartMaxSubsequence++;
//     }
//     cout << endl;
// }