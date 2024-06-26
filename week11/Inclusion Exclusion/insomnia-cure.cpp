#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Insomnia Cure
«One dragon. Two dragon. Three dragon», — the princess was counting. 
She had trouble falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at best she could. 
Tonight she imagined that all dragons were here to steal her, and she was fighting them off. 

Every k-th dragon got punched in the face with a frying pan. 
Every l-th dragon got his tail shut into the balcony door. 
Every m-th dragon got his paws trampled with sharp heels. 
Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the princess counted a total of d dragons?

Input: Input data contains integer numbers k, l, m, n and d, each number in a separate line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 10^5).

Output: Output the number of damaged dragons.
*/

int main(){
    ll k, l, m, n, numDragons;
    cin >> k;
    cin >> l;
    cin >> m;
    cin >> n;
    cin >> numDragons;

    ll damaged = numDragons;
    // simply loop through from 1 to numDragons (inclusive) and check if the dragon is divisible by k, l, m, or n (if NOT divisble by any, then it is unharmed)
    for(int i = 1; i <= numDragons; i++){
        if(i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0) damaged--;
    }
    cout << damaged << endl;
}