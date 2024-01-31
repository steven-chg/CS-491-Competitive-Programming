#include <bits/stdc++.h>

using namespace std;

/* Explicit Counts
Today we are going to add up a bunch of numbers and then subtract a bunch of numbers from it. 
All you have to do is read them all in!

Input: The first line is the number 1≤𝑁≤10 giving the number of test cases. 
For each test case, the first line contains two numbers 0≤𝑇𝑎≤100 and 0≤𝑇𝑠≤100, the number of items to add and the number of 
items to subtract, respectively. This is followed by 𝑇𝑎+𝑇𝑠 numbers 𝑎1,...,𝑎𝑇𝑎,𝑏1,...𝑏𝑇𝑠. Each number will be on its own line, 
and range from -1000 to 1000.

Output: For each test case, output the sum Σ𝑇𝑎𝑖𝑎𝑖−Σ𝑇𝑠𝑖𝑏𝑖
*/

int main() {
    int numCases, numAdd, numSub, currentNum;
    // Get the number of test cases
    scanf("%d", &numCases);
    // Loop for number of test cases
    while(numCases){
        // Reset running output for each test case
        int output = 0;
        // Retrieve # of additions and subtractions in each test case
        scanf("%d %d", &numAdd, &numSub);
        // Loop for total number of operations for each test case
        while(numAdd + numSub){
            // First numAdd inputs will be addition operations
            if(numAdd){
                // Case where you add; retrieve and add number
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
        // Print output for each test case; decrement # of cases
        printf("%d\n", output);
        numCases--;
    }
    return 0;
}