#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Checkout Assistant
Bob came to a cash & carry store, put n items into his trolley, and went to the checkout counter to pay. 
Each item is described by its price ci and time ti in seconds that a checkout assistant spends on this item. 
While the checkout assistant is occupied with some item, Bob can steal some other items from his trolley. 
To steal one item Bob needs exactly 1 second. What is the minimum amount of money that Bob will have to pay to the checkout assistant? 
Remember, please, that it is Bob, who determines the order of items for the checkout assistant.

Input: The first input line contains number n (1 ≤ n ≤ 2000). 
In each of the following n lines each item is described by a pair of numbers ti, ci (0 ≤ ti ≤ 2000, 1 ≤ ci ≤ 10^9). 
If ti is 0, Bob won't be able to steal anything, while the checkout assistant is occupied with item i.

Output: Output one number — answer to the problem: what is the minimum amount of money that Bob will have to pay.
*/

int main(){
    ll numItems;
    cin >> numItems;

    // store the (# items (time + 1 to include purchased item itself), cost)
    vector< pair<ll, ll> > costItems;
    costItems.push_back(make_pair(0, 0)); 
    vector<ll> dp;
    dp.push_back(0);
    for(int item = 1; item <= numItems; item++){
        ll time, cost;
        cin >> time >> cost;
        costItems.push_back(make_pair(time+1, cost));
        dp.push_back(2000*1e9+1);
    }

    /* Recursion w/Memoization DP
    - Define dp[z] as minimum cost to buy the first z items (inclusive)
    - Base Case: dp[0] = 0; else, initialize to a value greater than 2000*10^9
    */

    // look at items one by one to include them in our calculations
    for(int i = 1; i <= numItems; i++){
        // whenever we include a new 'purchase', we reanalyze cost to buy the first j items (inclusive)
        for(int j = numItems; j >= 0; j--){
            // the case where buying item i cannot allow us to get all j items (e.g. we can only get 3 items with item i but we want 4)
            if(j > costItems[i].first){
                // we find the minimum between original minimum cost to buy first j items and cost to buy item i and original cost to buy remaining items (e.g. cost to buy item i and the first 4-3 = 1 item)
                dp[j] = min(dp[j], dp[j - costItems[i].first] + costItems[i].second);
            } else{
                // the case where buying item i can allow us to cover j items, then we just find minimum between original minimum cost to buy first j items and the new cost of purchase for item i
                dp[j] = min(dp[j], costItems[i].second);
            }
        }
    }
    cout << dp[numItems] << endl;
}

/* FAILS TEST CASE 15 */
// // custom sort function that accounts for cost/item ratio being the same
// bool sortCostItems(pair<double, pair<ll, ll> > pair1, pair<double, pair<ll, ll> > pair2){
//     // sort by cost per item in ascending order
//     if (pair1.first != pair2.first) {
//         return pair1.first < pair2.first;
//     }
//     // if cost per item is the same, sort by the number of items covered in descending order
//     return pair1.second.first > pair2.second.first;
// }

// int main(){
//     ll numItems;
//     cin >> numItems;
//     // we store the (cost/item, # items, cost)
//     vector< pair<double, pair<ll, ll> > > costItems;

//     /* Notes:
//     - given the time and cost of each item, we can essentially find the number of items that we can cover for a given cost 
//     (time = number of items we can cover - 1 for the given cost)
//     - we store the cost/item and sort in ascending order by that value
//     - we then go through the vector in order then add up the costs and # items until it exceeds total number of items that we need to buy
//     - if an item covers more than totalItems, then you need to perform further checks to ensure there isn’t another 
//     solution with smaller total cost that also covers totalItems
//     */

//     /* BUGS:
//     - we need to account for the possibility where the ratio is cost/item is the same, with the latter being the solution
//     */

//     for(int item = 0; item < numItems; item++){
//         ll time, cost;
//         cin >> time >> cost;
//         costItems.push_back(make_pair(((double) cost) / (time+1), make_pair(time+1, cost)));
//     }

//     // sort in ascending order by cost/item
//     sort(costItems.begin(), costItems.end(), sortCostItems);

//     ll itemsLeft = numItems;
//     ll minCost = 0;
//     for(int i = 0; i < numItems; i++){
//         if(itemsLeft > 0){
//             if(itemsLeft - costItems[i].second.first >= 0){
//                 // purchasing this item won't cover more than the total number of remaining items
//                 itemsLeft -= costItems[i].second.first;
//                 minCost += costItems[i].second.second;
//             } else{
//                 // purchasing this item will cover more than the total number of remaining items
//                 // we need to perform further checks to ensure there isn't another solution with smaller total cost that also covers total number of remaining items
//                 ll currentMinCost = costItems[i].second.second;
//                 for(int j = i+1; j < numItems; j++){
//                     if((costItems[j].second.second < currentMinCost) && (itemsLeft - costItems[j].second.first <= 0)){
//                         currentMinCost = costItems[j].second.second;
//                     }
//                 }
//                 minCost += currentMinCost;
//                 // break out of for loop since we accounted for all items
//                 break;
//             }
//         }
//     }
//     cout << minCost << endl;
// }