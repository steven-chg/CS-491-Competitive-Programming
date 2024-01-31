#include <bits/stdc++.h>

using namespace std;

/* Higher or Lower
I have a secret number between 1 and 10^18. Guess the number in under 60 guesses. When you guess a number I will tell you:
    HIGHER - if my number is higher than your guess.
    LOWER - if my number is lower than your guess.
    CORRECT - if my number is exactly your guess.

Interaction: In one line, send your guess. The judge will respond with HIGHER, LOWER, or CORRECT. This will be repeated up to 60 times.

Upon receiving a CORRECT from the judge, terminate your program immediately.
*/

int main(){

    // declare variable to track lower bound, upperbound, and current guess value
    long long int lowerBound = 1; long long int upperBound = 1e18; long long int guessValue;

    // declare string for storing the result from the judge
    string judgeResult;

    // loop for a maximum of 60 guesses
    for(int guessNumber = 0; guessNumber < 60; guessNumber++){
        // set the current guess value as the middle of current lower and upper bound 
        guessValue = (lowerBound + upperBound) / 2;

        // send the guess to the judge; half the guess range each time, depending on if the result is higher or lower
        cout << guessValue << endl;

        // retrieve the judge's response
        cin >> judgeResult;

        // determine judge response and update guess value accordingly
        if(judgeResult == "HIGHER"){
            // if the guess value was too low, then we update the lower bound accordingly (+ 1 since guessValue isn't the correct value)
            lowerBound = guessValue + 1;
        } else if(judgeResult == "LOWER"){
            // if the guess value was too high, then we update the upper bound accordingly (- 1 since guessValue isn't the correct value)
            upperBound = guessValue - 1;
        } else if(judgeResult == "CORRECT"){
            // if the guess value is correct, terminate the program
            return 0;
        }
    }
}