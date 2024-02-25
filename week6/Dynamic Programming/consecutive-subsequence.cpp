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

int main(){
    ll arrayLength;
    cin >> arrayLength;

    /* Notes:
    - use a map to store the max. subsequence length ending at each value 
    - where key = ending value & value = max. subsequence length ending at the key value
    - we can correctly find the max. subsequence length by going through the array in order
    then setting map[ending value] = map[ending value - 1] + 1
    */

    vector<ll> array(arrayLength);
    map<ll, ll> maxSubsequenceLength;

    for(int i = 0; i < arrayLength; i++){
        cin >> array[i];
    } 

    ll maxLength = 1;
    // track the ending value of the subsequence with maximum length 
    ll maxValue = -1;
    for(int i = 0; i < arrayLength; i++){
        maxSubsequenceLength[array[i]] = maxSubsequenceLength[array[i] - 1] + 1;
        // update maximum length of possible consecutive subsequence and its ending value when appropriate
        if(maxSubsequenceLength[array[i]] > maxLength){
            maxLength = maxSubsequenceLength[array[i]];
            maxValue = array[i];
        }
    }

    cout << maxLength << endl;

    // if maximum subsequence length is 1, then just return index 1
    if(maxLength == 1){
        cout << "1" << endl;
    } else{
        // else, find the starting value of the subsequence and loop through the array to find indices
        ll currentValue = maxValue - maxLength + 1;
        for(int i = 0; i < arrayLength; i++){
            if(currentValue == array[i]){
                cout << (i + 1) << " ";
                currentValue++;
            }
            if(currentValue > maxValue) break;
        }
        cout << endl;
    }
}

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
//     vector< pair<ll, ll> > array(arrayLength + 1);

//     for(int i = 1; i <= arrayLength; i++){
//         cin >> array[i].first;
//         array[i].second = i;
//     }

//     // sort in ascending order by the value of the array
//     sort(array.begin(), array.end());

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
