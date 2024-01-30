#include <bits/stdc++.h>

using namespace std;

/* Worms
It is lunch time for Mole. His friend, Marmot, prepared him a nice game for lunch.
Marmot brought Mole n ordered piles of worms such that i-th pile contains ai worms. 
He labeled all these worms with consecutive integers: worms in first pile are labeled with numbers 1 to a1, worms in second pile are labeled with 
numbers a1 + 1 to a1 + a2 and so on. See the example for a better understanding.

Mole can't eat all the worms (Marmot brought a lot) and, as we all know, Mole is blind, so Marmot tells him the labels of the best juicy worms. 
Marmot will only give Mole a worm if Mole says correctly in which pile this worm is contained.

Poor Mole asks for your help. For all juicy worms said by Marmot, tell Mole the correct answers.

Input: The first line contains a single integer n (1 ≤ n ≤ 10^5), the number of piles.
The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^3, a1 + a2 + ... + an ≤ 10^6), where ai is the number of worms in the i-th pile.
The third line contains single integer m (1 ≤ m ≤ 10^5), the number of juicy worms said by Marmot.
The fourth line contains m integers q1, q2, ..., qm (1 ≤ qi ≤ a1 + a2 + ... + an), the labels of the juicy worms.

Output: Print m lines to the standard output. The i-th line should contain an integer, representing the number of the pile where the worm labeled with the number qi is.
*/

int main(){
    // retrieve the number of piles
    long long int numPiles;
    cin >> numPiles;

    // create a vector that stores the running sum of worms in each pile (initialize values to 0)
    vector<long long int> runningSumofWorms(numPiles + 1, 0);
    for(int pileNum = 1; pileNum <= numPiles; pileNum++){
        long long int numWormsCurrentPile;
        cin >> numWormsCurrentPile;
        runningSumofWorms[pileNum] = runningSumofWorms[pileNum - 1] + numWormsCurrentPile;
    }

    // retrieve the number of juicy worms
    long long int numJuicyWorms;
    cin >> numJuicyWorms;

    // declare a vector to store the pile number of the juicy worms
    vector<long long int> juicyWormPile(numJuicyWorms);

    // loop through number of juicy worms and find the pile that contains the worms 
    for(int juicyWormNum = 0; juicyWormNum < numJuicyWorms; juicyWormNum++){
        // retrieve the label of the current juicy worm
        long long int juicyWormLabel;
        cin >> juicyWormLabel;
        
        // initialize the lower and upper bound on the indices  
        long long int lowerBoundIndex = 1;
        long long int upperBoundIndex = numPiles;
    
        // loop until we narrow in onto an index separated by 1 space
        while(lowerBoundIndex != upperBoundIndex - 1){
            // find the index into the vector we are currently looking at
            long long int currentIndex = (lowerBoundIndex + upperBoundIndex) / 2;
            
            // the juicy worm is in the lower half piles
            if(runningSumofWorms[currentIndex] > juicyWormLabel){
                upperBoundIndex = currentIndex;
            } else if(runningSumofWorms[currentIndex] < juicyWormLabel){
            // the juicy worm is in the upper half pile
                lowerBoundIndex = currentIndex;
            } else if(runningSumofWorms[currentIndex] == juicyWormLabel){
            // the juicy worm is in the currentIndex we are looking at
                lowerBoundIndex = currentIndex;
                upperBoundIndex = currentIndex + 1;
            }
        }

        // check if in the upperBoundIndex or lowerBoundIndex number pile
        if(runningSumofWorms[lowerBoundIndex] >= juicyWormLabel){
            juicyWormPile[juicyWormNum] = lowerBoundIndex;
        } else{
            juicyWormPile[juicyWormNum] = upperBoundIndex;
        }
    }

    // print the output of the piles the juicy worms belong to
    for(int juicyWorm = 0; juicyWorm < numJuicyWorms; juicyWorm++){
        cout << juicyWormPile[juicyWorm] << "\n";
    }
}