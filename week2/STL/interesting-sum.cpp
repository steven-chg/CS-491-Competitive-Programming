#include <bits/stdc++.h>

using namespace std;

/* Interesting Sum
You are given an array 𝑎 that contains 𝑛 integers. You can choose any proper subsegment 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟 of this array, meaning you can choose any two integers 1≤𝑙≤𝑟≤𝑛, where 𝑟−𝑙+1<𝑛. 
We define the beauty of a given subsegment as the value of the following expression: max(𝑎1,𝑎2,…,𝑎𝑙−1,𝑎𝑟+1,𝑎𝑟+2,…,𝑎𝑛)−min(𝑎1,𝑎2,…,𝑎𝑙−1,𝑎𝑟+1,𝑎𝑟+2,…,𝑎𝑛)+max(𝑎𝑙,…,𝑎𝑟)−min(𝑎𝑙,…,𝑎𝑟).
Please find the maximum beauty among all proper subsegments.

Input: The first line contains one integer 𝑡 (1≤𝑡≤1000) — the number of test cases. Then follow the descriptions of each test case.
The first line of each test case contains a single integer 𝑛 (4≤𝑛≤10^5) — the length of the array.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤10^9) — the elements of the given array.
It is guaranteed that the sum of 𝑛 over all test cases does not exceed 10^5.

Output: For each testcase print a single integer — the maximum beauty of a proper subsegment.
*/

int main(){
    
    // Get number of test cases
    int numCases;
    scanf("%d", &numCases);

    // Loop through all test cases
    while(numCases){
        // Get number of integers in array
        int numInts;
        scanf("%d\n", &numInts);

        // Declare vector to store the integers & insert integers into vector
        vector<int> intArray;
        int currentInt;
        while(numInts > 0){
            cin >> currentInt;
            intArray.push_back(currentInt);
            numInts--;
        }

        /* SOLVE BY SORTING */
        // Sort the vector; add the two largest numbers and subtract by the two smallest numbers to get the maximum beauty
        int maximumBeauty = 0;
        sort(intArray.begin(), intArray.end());   // in ascending order
        maximumBeauty = intArray[intArray.size() - 1] + intArray[intArray.size() - 2] - intArray[0] - intArray[1];

        /* THIS APPROACH EXCEEDS TIME LIMIT*/
        // // Find the maximum beauty of a subsegment by going through all possible subsegments
        // int maximumBeauty = 0; // Initialize to 0
        // for(auto l = intArray.begin(); l != intArray.end(); ++l){  
        //     for(auto r = l; r != intArray.end(); ++r){ // r has to start at l (NOT at beginniing of the array)
        //         // Find the max and min values for values inside l and r 
        //         int maxInside = 0;
        //         int minInside = pow(2, 9);
        //         for(auto i = l; i != r; ++i){
        //             if(*i > maxInside) maxInside = *i;
        //             if(*i < minInside) minInside = *i;
        //         }
        //         // Check against element r as well
        //         if(*r > maxInside) maxInside = *r;
        //         if(*r < minInside) minInside = *r;

        //         // Find the max and min values for values outside l and r
        //         int maxOutside = 0;
        //         int minOutside = pow(2, 9);
        //         // Check the left side
        //         for(auto j = intArray.begin(); j != l; ++j){
        //             if(*j > maxOutside) maxOutside = *j;
        //             if(*j < minOutside) minOutside = *j;
        //         }
        //         // Check the right side
        //         for(auto k = r+1; k != intArray.end(); ++k){
        //             if(*k > maxOutside) maxOutside = *k;
        //             if(*k < minOutside) minOutside = *k;
        //         }
        //         // Find the beauty of this current subsegment and update the maximum beauty if it is greater
        //         if((maxOutside - minOutside + maxInside - minInside) > maximumBeauty) maximumBeauty = (maxOutside - minOutside + maxInside - minInside);
        //     }
        // }
    
        // Print the maximum beauty 
        printf("%d\n", maximumBeauty);

        // Decrement number of test cases 
        numCases--;
    }

    return 0;
}