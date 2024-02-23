#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Minimize Distance
A total of 𝑛 depots are located on a number line. Depot 𝑖 lies at the point 𝑥𝑖 for 1≤𝑖≤𝑛.

You are a salesman with 𝑛 bags of goods, attempting to deliver one bag to each of the 𝑛 depots. You and the 𝑛 bags are initially at the origin 0. You can carry up to 𝑘 bags at a time. 
You must collect the required number of goods from the origin, deliver them to the respective depots, and then return to the origin to collect your next batch of goods.

Calculate the minimum distance you need to cover to deliver all the bags of goods to the depots. You do not have to return to the origin after you have delivered all the bags.

Input: Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤10500). Description of the test cases follows.

The first line of each test case contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤2⋅10^5).

The second line of each test case contains 𝑛 integers 𝑥1,𝑥2,…,𝑥𝑛 (−10^9≤𝑥𝑖≤10^9). It is possible that some depots share the same position.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅10^5.

Output: For each test case, output a single integer denoting the minimum distance you need to cover to deliver all the bags of goods to the depots.
*/

int main(){
    ll numCases;
    cin >> numCases;

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll numDepots, maxBags;
        cin >> numDepots >> maxBags;

        // vectors that will store magnitudes of distances on each side (distance positive on right side, negative on left side)
        vector<ll> positiveDistance;
        vector<ll> negativeDistance;

        for(int depot = 0; depot < numDepots; depot++){
            ll currentDepotDistance;
            cin >> currentDepotDistance;
            // split into positive (right) and negative (left) (store their magnitude and ignore depots at position 0)
            if(currentDepotDistance > 0) positiveDistance.push_back(currentDepotDistance);
            else if(currentDepotDistance < 0) negativeDistance.push_back(abs(currentDepotDistance));
        }

        // sort the distances in descending order 
        sort(positiveDistance.begin(), positiveDistance.end(), greater<ll>());
        sort(negativeDistance.begin(), negativeDistance.end(), greater<ll>());

        // find which side we want our final delivery to be (whichever value is greater)
        ll finalDeliveryPos = 0, finalDeliveryNeg = 0;                                          /* NEED TO INITIALIZE OR ELSE MIGHT CARRY RANDOM VALUE IN */
        if(positiveDistance.size() != 0) finalDeliveryPos = positiveDistance[0];
        if(negativeDistance.size() != 0) finalDeliveryNeg = negativeDistance[0];

        ll totalDistance = 0;
        // find number of delivery runs needed on each side
        ll numDeliveriesPos = ceil((positiveDistance.size() + maxBags - 1)/ maxBags);
        ll numDeliveriesNeg = ceil((negativeDistance.size() + maxBags - 1) / maxBags);

        // cout << numDeliveriesPos << endl;
        // cout << numDeliveriesNeg << endl;

        /* Notes:
        - start with the final delivery on each side, then work slowly backwards (closer and closer to origin)
        */

        // if finalDeliveryPos >= finalDeliveryNeg, then it means our final delivery should be to the right side, vice versa
        if(finalDeliveryPos >= finalDeliveryNeg){
            // find total delivery distance for positive side
            ll currentPosIndex = 0;
            for(int posDeliveryNum = numDeliveriesPos; posDeliveryNum > 0; posDeliveryNum--){
                if(posDeliveryNum == numDeliveriesPos){
                    //final delivery (furthest delivery)
                    totalDistance += positiveDistance[currentPosIndex];
                    currentPosIndex += maxBags;
                } else {
                    // not the final delivery
                    totalDistance += 2*positiveDistance[currentPosIndex];
                    currentPosIndex += maxBags;
                }
            }

            // find total delivery distance for negative side
            ll currentNegIndex = 0;
            for(int negDeliveryNum = numDeliveriesNeg; negDeliveryNum > 0; negDeliveryNum--){
                totalDistance += 2*negativeDistance[currentNegIndex];
                currentNegIndex += maxBags;
            }

        } else{
            // find total delivery distance for positive side
            ll currentPosIndex = 0;
            for(int posDeliveryNum = numDeliveriesPos; posDeliveryNum > 0; posDeliveryNum--){
                totalDistance += 2*positiveDistance[currentPosIndex];
                currentPosIndex += maxBags;
            }

            // find total delivery distance for negative side
            ll currentNegIndex = 0;
            for(int negDeliveryNum = numDeliveriesNeg; negDeliveryNum > 0; negDeliveryNum--){
                if(negDeliveryNum == numDeliveriesNeg){
                    //final delivery (furthest delivery)
                    totalDistance += negativeDistance[currentNegIndex];
                    currentNegIndex += maxBags;
                } else{
                    // not the final delivery
                    totalDistance += 2*negativeDistance[currentNegIndex];
                    currentNegIndex += maxBags;
                }
            }
        }
        cout << totalDistance << endl;
    }
}