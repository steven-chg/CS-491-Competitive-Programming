#include <bits/stdc++.h>

using namespace std;

/* End Markers
Today we are going to add up a bunch of numbers and then subtract a bunch of numbers from it. All you have to do is read them all in!

Input: Each test case starts with a line containing two numbers 0≤𝑇𝑎≤100 and 0≤𝑇𝑠≤100, the number of items to add and the 
number of items to subtract, respectively. This is followed by 𝑇𝑎+𝑇𝑠 numbers 𝑎1,...,𝑎𝑇𝑎,𝑏1,...𝑏𝑇𝑠. Each number will be on its 
own line, and range from -1000 to 1000. The tests are done when you read a zero for both 𝑇𝑎 and 𝑇𝑠.

Output: For each test case, output the sum Σ𝑇𝑎𝑖𝑎𝑖−Σ𝑇𝑠𝑖𝑏𝑖
*/

int main() {
    int numAdd, numSub, currentNum;
    // Watch out for condition check (NEED || instead of &&; since we want to continue if either input is non-zero)
    while(scanf("%d %d", &numAdd, &numSub) && (numAdd != 0 || numSub != 0)){
        // Reset running output for each test case
        int output = 0;
        // Loop for total number of operations for each test case
        while(numAdd + numSub){
            // First numAdd inputs will be addition operations
            if(numAdd){
                // Case where you add; retrieve and add
                scanf("%d", &currentNum);
                output += currentNum;
                // Decrement to get remaining numbers to add
                numAdd--;
            // After addition, remaining operations are subtraction
            }else{
                // Case where you subtract; retrieve and subtract
                scanf("%d", &currentNum);
                output -= currentNum;
                // Decrement to get remaining numbers to subtract
                numSub--;
            }
        }
        // Print output for each test case
        printf("%d\n", output);
    }
    return 0;
}