#include <bits/stdc++.h>

using namespace std;

/* Searching Local Minimum
This is an interactive problem.
Homer likes arrays a lot and he wants to play a game with you. Homer has hidden from you a permutation 𝑎1,𝑎2,…,𝑎𝑛 of integers 1 to 𝑛. You are asked to find any index 𝑘
(1≤𝑘≤𝑛) which is a local minimum.

For an array 𝑎1,𝑎2,…,𝑎𝑛, an index 𝑖 (1≤𝑖≤𝑛) is said to be a local minimum if 𝑎𝑖<min{𝑎𝑖−1,𝑎𝑖+1}, where 𝑎0=𝑎𝑛+1=+∞. 
An array is said to be a permutation of integers 1 to 𝑛, if it contains all integers from 1 to 𝑛 exactly once.

Initially, you are only given the value of n without any other information about this permutation.

At each interactive step, you are allowed to choose any 𝑖 (1≤𝑖≤𝑛) and make a query with it. As a response, you will be given the value of 𝑎𝑖.

You are asked to find any index 𝑘 which is a local minimum after at most 100 queries.

Interaction: You begin the interaction by reading an integer 𝑛 (1≤𝑛≤10^5) on a separate line.
To make a query on index 𝑖 (1≤𝑖≤𝑛), you should output "? 𝑖" in a separate line. Then read the value of 𝑎𝑖 in a separate line. 
The number of the "?" queries is limited within 100.

When you find an index 𝑘 (1≤𝑘≤𝑛) which is a local minimum, output "! 𝑘" in a separate line and terminate your program.

In case your query format is invalid, or you have made more than 100 "?" queries, you will receive Wrong Answer verdict.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:
    fflush(stdout) or cout.flush() in C++;
    System.out.flush() in Java;
    flush(output) in Pascal;
    stdout.flush() in Python;
see documentation for other languages.

Hack Format: The first line of the hack should contain a single integer 𝑛 (1≤𝑛≤10^5).
The second line should contain 𝑛 distinct integers 𝑎1,𝑎2,…,𝑎n (1≤𝑎𝑖≤𝑛).
*/

int main(){
    // retrieve the n, or the max value in the permutation
    long long int nMaxValue;
    cin >> nMaxValue;
 
    // declare and initialize the upper and lower bounds 
    long long int lowerBoundIndex = 1; long long int upperBoundIndex = nMaxValue;
    long long int guessIndex;  
 
    // declare variables to check current, previous, and next index values
    long long int currentValue, previousValue, nextValue;
 
    // loop while lowerBoundIndex is smaller than upperBoundIndex
    while(lowerBoundIndex < upperBoundIndex){
        // since we are rounding down, it means that we don't have to ever worry about accsesing n + 1 since that is only possible when lowerBoundIndex = upperBoundIndex = n (won't pass while loop condition)
        guessIndex = (lowerBoundIndex + upperBoundIndex) / 2;       
        
        // get the current and next values
        cout << "? " << guessIndex << endl;
        cin >> currentValue; 
        cout << "? " << guessIndex+1 << endl;
        cin >> nextValue; 

        if(currentValue < nextValue){
            // if next value is greater then update upper bound
            upperBoundIndex = guessIndex;
        } else{
            // if next value is smalleer then update lower bound
            lowerBoundIndex = guessIndex + 1;
        }
    }

    // lower bound will contain the index of the minimum value 
    cout << "! " << lowerBoundIndex << endl;
    
}


/* ORIGINAL NON OPTIMIZED CODE */
// int main(){
//     // retrieve the n, or the max value in the permutation
//     long int nMaxValue;
//     cin >> nMaxValue;
 
//     // declare and initialize the upper and lower bounds 
//     long int lowerBoundIndex = 1; long int upperBoundIndex = nMaxValue;
//     long int guessIndex;  
 
//     // declare variables to check current, previous, and next index values
//     long int currentValue, previousValue, nextValue;
 
//     do{
//         guessIndex = (lowerBoundIndex + upperBoundIndex) / 2;
//         // everytime, we finish a check, updates towards decreasing side
//         // if guessIndex is index 1, then we just need to check the guessIndex and guessIndex + 1 values; update bounds accordingly
//         if((guessIndex - 1 < 1)){
//             // get the current and next values
//             cout << "? " << guessIndex << endl;
//             cin >> currentValue; 
//             cout << "? " << guessIndex+1 << endl;
//             cin >> nextValue; 
 
//             // check if the current value is a local minimum
//             if(currentValue < nextValue){
//                 // found the local minimum 
//                 cout << "! " << guessIndex << endl;
//                 break;
//             } 
 
//             // if not the local minimum, make the lower bound index guessIndex + 1 (since value at guessIndex is greater than value at guessIndex + 1)
//             lowerBoundIndex = guessIndex + 1;
    
//         } else if((guessIndex + 1 > nMaxValue)){
//         // if guessIndex is nMaxValue index, then we just need to check the guessIndex and guessIndex - 1 values; update bounds accordingly
//             // get the current and previous values
//             cout << "? " << guessIndex << endl;
//             cin >> currentValue;
//             cout << "? " << guessIndex-1 << endl;
//             cin >> previousValue;
 
//             // check if the current value is a local minimum
//             if(currentValue < previousValue){
//                 // found the local minimum
//                 cout << "! " << guessIndex << endl;
//                 break;
//             }
            
//             // if not the local minimum, make the upper bound index guessIndex - 1 (since value at guessIndex is greater than value at guessIndex - 1)
//             upperBoundIndex = guessIndex - 1;
 
//         } else{
//         // we need to check guessIndex, guessIndex - 1, and guessIndex + 1 values; update bounds accordingly 
//             // get the current, previous, and next values
//             cout << "? " << guessIndex << endl;
//             cin >> currentValue;
//             cout << "? " << guessIndex-1 << endl;
//             cin >> previousValue;
//             cout << "? " << guessIndex+1 << endl;
//             cin >> nextValue;
 
//             // check if the current value is a local minimum
//             if(currentValue < previousValue && currentValue < nextValue){
//                 // found the local minimum
//                 cout << "! " << guessIndex << endl;
//                 break;
//             } else if(currentValue > previousValue){
//                 // if current value is greater than previous value, then upperbound should be updated 
//                 upperBoundIndex = guessIndex - 1;
//             } else if(currentValue > nextValue){
//                 // if current value is greater than the next value, then lowerbound should be updated
//                 lowerBoundIndex = guessIndex + 1;
//             }
//         }
//     }while(1);
// }