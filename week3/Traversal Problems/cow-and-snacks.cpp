#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Cow and Snacks
The legendary Farmer John is throwing a huge party, and animals from all over the world are hanging out at his house.
His guests are hungry, so he instructs his cow Bessie to bring out the snacks! Moo!
There are 𝑛 snacks flavors, numbered with integers 1,2,…,𝑛. Bessie has 𝑛 snacks, one snack of each flavor. 
Every guest has exactly two favorite flavors. The procedure for eating snacks will go as follows:

First, Bessie will line up the guests in some way.
Then in this order, guests will approach the snacks one by one.
Each guest in their turn will eat all remaining snacks of their favorite flavor. 
In case no favorite flavors are present when a guest goes up, they become very sad.
Help Bessie to minimize the number of sad guests by lining the guests in an optimal way.

Input: The first line contains integers 𝑛 and 𝑘 (2≤𝑛≤10^5, 1≤𝑘≤10^5), the number of snacks and the number of guests.

The 𝑖-th of the following 𝑘 lines contains two integers 𝑥𝑖 and 𝑦𝑖 (1≤𝑥𝑖,𝑦𝑖≤𝑛, 𝑥𝑖≠𝑦𝑖), favorite snack flavors of the 𝑖-th guest.

Output: Output one integer, the smallest possible number of sad guests.
*/

// declare a 2D vector with 1e5 + 1 rows (max. number of snacks), where each row stores the snacks that have been paired with it as a favorite snack pair
vector< vector<ll> > favoriteSnacksGraph(1e5+1);

// declare a vector to keep track of which snacks have been picked/covered (initialize to false)
vector<bool> snackPicked(1e5+1, false);

// declare a global variable to store number of connected components 
ll numberNodesInConnectedComponent;

void depth_first_search(ll snackToSearch){
    // mark current node as having been visited/picked
    snackPicked[snackToSearch] = true;
    // increment number of nodes in connected component
    numberNodesInConnectedComponent += 1;

    // loop through neighboring nodes/snacks of the current snack
    for(ll neighbor = 0; neighbor < favoriteSnacksGraph[snackToSearch].size(); neighbor++){
        ll neighborSnackNum = favoriteSnacksGraph[snackToSearch][neighbor];
        // if the neighbor has not been visited, then visit it
        if(snackPicked[neighborSnackNum] == false){ 
            depth_first_search(neighborSnackNum);
        }
    }
}

int main(){
    // retrieve number of snacks and number of guests
    ll numSnacks, numGuests;
    cin >> numSnacks >> numGuests;

    /* Notes:
    - utilize a depth first search approach
    - we need to track the number of nodes in each connected component (or number of snacks)
    - note that if we have 3 snacks in a connected component, the maximum number of guests that we can serve is 2
    - therefore, we need to find the number of nodes in each connected component and subtract that by 1 to keep track of the number
    - of guests that we can serve (in the end, subtract total number of guests by the number of guests that we can serve)
    */

    // loop through all guests and get their favorite snacks
    for(int guestNum = 1; guestNum <= numGuests; guestNum++){
        ll snackOne, snackTwo;
        cin >> snackOne >> snackTwo;
        // store the pair
        favoriteSnacksGraph[snackOne].push_back(snackTwo);
        favoriteSnacksGraph[snackTwo].push_back(snackOne);
    }

    // initialize number of sad guests to be all guests
    ll numSadGuests = numGuests;

    // loop through all snacks 
    for(int snackNum = 1; snackNum <= numSnacks; snackNum++){
        // if the snack has not been picked/covered, perform depth first search on it 
        if(snackPicked[snackNum] == false){
            // everytime we perform a new search, reset the number of nodes in the connected component
            numberNodesInConnectedComponent = 0;
            depth_first_search(snackNum);
            // after we finish the search, decrement the number of sad guests
            numSadGuests -= (numberNodesInConnectedComponent - 1);
        }
    }

    cout << numSadGuests << endl;

}