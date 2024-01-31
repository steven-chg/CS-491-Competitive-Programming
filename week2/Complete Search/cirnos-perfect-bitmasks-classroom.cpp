#include <bits/stdc++.h>

using namespace std;

/* Cirno's Perfect Bitmasks Classroom
Cirno's perfect bitmasks classroom has just started!

Cirno gave her students a positive integer 𝑥. As an assignment, her students need to find the minimum positive integer 𝑦, which satisfies the following two conditions:
    𝑥 𝚊𝚗𝚍 𝑦>0
    𝑥 𝚡𝚘𝚛 𝑦>0
Where 𝚊𝚗𝚍 is the bitwise AND operation, and 𝚡𝚘𝚛 is the bitwise XOR operation.

Among the students was Mystia, who was truly baffled by all these new operators. Please help her!

Input: The first line of input contains a single integer 𝑡 (1≤𝑡≤10^3) — the number of input test cases.
For each test case, the only line of input contains one integer 𝑥 (1≤𝑥≤2^30).

Output: For each test case, print a single integer — the minimum number of 𝑦.
*/

int main(){
    // retrieve the number of test cases and loop for that number of times
    long long int numCases;
    cin >> numCases;
    for(long long int testCase = 0; testCase < numCases; testCase++){
        // retrieve x for each test case
        long long int x;
        cin >> x;

        /* 3 Possible Cases
        1: x contains more than one 1 bit, so we just need to set y to have the lowest 1 bit in x
        2: x contains one 1 bit only, and it is set at the first bit, so x = 1; therefore, smallest y is 3 or we need to set both the first and second bit of y to 1
        3: x contains one 1 bit only, and it is NOT set at the first bit, so set y to have the lowest 1 bit in x and then add 1 to y to set y's first bit to 1 as well 
        */

        // since we want x AND y to be greater than 0, it means that the smallest 1 bit in x also needs to appear in y (initialize y to that value)
        long long int y = (x & -x);  

        // at this point, y AND x > 0, check if y XOR x > 0 too (would only be possible if there are more than one 1 bit in x)
        if ((x ^ y) > 0){
            // if so, we found the minimum y value
            printf("%lld\n", y);
        } else{
        // in the case where there is only one 1 bit in x
            if(x == 1){
            // 1st case is where x == 1, if so, return 3 (since we have already set the first bit in y to 1, we just need to also set the 2nd bit to 1, which gives 3)
                printf("%lld\n", y + 2);
            } else{
            // 2nd case is where the bit in y that we set to 1 isn't the first bit, so we just need to set the first bit now 
                printf("%lld\n", y + 1);

            }
        }

        /* NOT THE MOST EFFICIENT ALGORITHM */
        // // loop until we find a y value that satisfies the conditions; initialize y to start from 1 (0 won't work since anything AND 0 will be 0)
        // for(long long int y = 0; ; y++){
        //     // check if current y value satisfies condition
        //     if((x & y) > 0 && (x ^ y) > 0){
        //         // if so, then print the value and break to next test case
        //         printf("%lld\n", y);
        //         break;
        //     }
        // }
    }
}