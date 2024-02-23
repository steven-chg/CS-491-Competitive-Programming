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

        vector<ll> positiveDistance;
        vector<ll> negativeDistance;

        for(int depot = 0; depot < numDepots; depot++){
            ll currentDepotDistance;
            cin >> currentDepotDistance;
            // split into positive and negative distances (store their magnitude and ignore depots at position 0)
            if(currentDepotDistance > 0) positiveDistance.push_back(currentDepotDistance);
            else if(currentDepotDistance < 0) negativeDistance.push_back(abs(currentDepotDistance));
        }

        // sort the distances in ascending order 
        sort(positiveDistance.begin(), positiveDistance.end(), less<ll>());
        sort(negativeDistance.begin(), negativeDistance.end(), less<ll>());

        // find which side we want our final delivery to be (whichever value is greater)
        ll finalDeliveryPos = 0, finalDeliveryNeg = 0;          /* NEED TO INITIALIZE OR ELSE MIGHT CARRY RANDOM VALUE IN */
        if(positiveDistance.size() != 0) finalDeliveryPos = positiveDistance[positiveDistance.size() - 1];
        if(negativeDistance.size() != 0) finalDeliveryNeg = negativeDistance[negativeDistance.size() - 1];

        ll totalDistance = 0;
        ll numDeliveriesPos = ceil((positiveDistance.size() + maxBags - 1)/ maxBags);
        ll numDeliveriesNeg = ceil((negativeDistance.size() + maxBags - 1) / maxBags);

        // cout << numDeliveriesPos << endl;
        // cout << numDeliveriesNeg << endl;

        // if finalDeliveryPos > finalDeliveryNeg, then it means our final delivery should be to the right side, vice versa
        if(finalDeliveryPos >= finalDeliveryNeg){
            // find total delivery distance for positive side
            ll currentPosIndex = maxBags - 1;
            for(int posDeliveryNum = 0; posDeliveryNum < numDeliveriesPos; posDeliveryNum++){
                if(posDeliveryNum != (numDeliveriesPos - 1) && posDeliveryNum != (numDeliveriesPos - 2)){
                    // not last or 2nd to last delivery
                    totalDistance += 2*positiveDistance[currentPosIndex];
                    currentPosIndex += maxBags;
                } else if(posDeliveryNum == (numDeliveriesPos - 2)){
                    // second to last delivery
                    totalDistance += 2*positiveDistance[positiveDistance.size() - 1 - maxBags];
                } else{
                    // last delivery
                    totalDistance += positiveDistance[positiveDistance.size() - 1];
                }
            }

            // find total delivery distance for negative side
            ll currentNegIndex = maxBags - 1;
            for(int negDeliveryNum = 0; negDeliveryNum < numDeliveriesNeg; negDeliveryNum++){
                if(negDeliveryNum != (numDeliveriesNeg - 1) && negDeliveryNum != (numDeliveriesNeg - 2)){
                    // not last or 2nd to last delivery
                    totalDistance += 2*negativeDistance[currentNegIndex];
                    currentNegIndex += maxBags;
                } else if(negDeliveryNum == (numDeliveriesNeg - 2)){
                    // second to last delivery
                    totalDistance += 2*negativeDistance[negativeDistance.size() - 1 - maxBags];
                } else{
                    // last delivery
                    totalDistance += 2*negativeDistance[negativeDistance.size() - 1];
                }
            }

        } else if (finalDeliveryNeg > finalDeliveryPos) {
            // find total delivery distance for positive side
            ll currentPosIndex = maxBags - 1;
            for(int posDeliveryNum = 0; posDeliveryNum < numDeliveriesPos; posDeliveryNum++){
                if(posDeliveryNum != (numDeliveriesPos - 1) && posDeliveryNum != (numDeliveriesPos - 2)){
                    // not last or 2nd to last delivery
                    totalDistance += 2*positiveDistance[currentPosIndex];
                    currentPosIndex += maxBags;
                } else if(posDeliveryNum == (numDeliveriesPos - 2)){
                    // second to last delivery
                    totalDistance += 2*positiveDistance[positiveDistance.size() - 1 - maxBags];
                } else{
                    // last delivery
                    totalDistance += 2*positiveDistance[positiveDistance.size() - 1];
                }
            }

            // find total delivery distance for negative side
            ll currentNegIndex = maxBags - 1;
            for(int negDeliveryNum = 0; negDeliveryNum < numDeliveriesNeg; negDeliveryNum++){
                if(negDeliveryNum != (numDeliveriesNeg - 1) && negDeliveryNum != (numDeliveriesNeg - 2)){
                    // not last or second to last delivery
                    totalDistance += 2*negativeDistance[currentNegIndex];
                    currentNegIndex += maxBags;
                } else if(negDeliveryNum == numDeliveriesNeg - 2){
                    // second to last delivery
                    totalDistance += 2*negativeDistance[negativeDistance.size() - 1 - maxBags];
                } else{
                    // last delivery
                    totalDistance += negativeDistance[negativeDistance.size() - 1];
                }
            }
        }

        cout << totalDistance;

    }

}