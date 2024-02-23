#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* XY Sequence
You are given four integers 𝑛, 𝐵, 𝑥, and 𝑦. You should build a sequence 𝑎0,𝑎1,𝑎2,…,𝑎𝑛 where 𝑎0=0 and for each 𝑖≥1 you can choose:
    either 𝑎𝑖 = 𝑎(subscript i - 1) + 𝑥 
    or 𝑎𝑖 = 𝑎(subscript i - 1) − 𝑦.

Your goal is to build such a sequence 𝑎 that 𝑎𝑖≤𝐵 for all 𝑖 and ∑ (i = 0 to i = n) 𝑎i is maximum possible.

Input: The first line contains a single integer 𝑡 (1≤𝑡≤10^4) — the number of test cases. Next 𝑡 cases follow.

The first and only line of each test case contains four integers 𝑛, 𝐵, 𝑥, and 𝑦 (1≤𝑛≤2⋅10^5; 1≤𝐵,𝑥,𝑦≤10^9).

It's guaranteed that the total sum of 𝑛 doesn't exceed 2⋅10^5.

Output: For each test case, print one integer — the maximum possible ∑ (i = 0 to i = n) 𝑎i.
*/

int main(){
    // retrieve the number of test cases
    ll numCases;
    scanf("%lld", &numCases);

    for(int caseNum = 0; caseNum < numCases; caseNum++){
        ll n, B, x, y;
        scanf("%lld %lld %lld %lld", &n, &B, &x, &y);

        // for each test case, track previous value chosen and the running sum of the sequence
        ll runningSum = 0;
        ll previousVal = 0;

        // go through the entire sequence
        for(int index = 0; index < n; index++){
            ll currentValue;
            // choose the maximum current value possible
            if(previousVal + x <= B){
                currentValue = previousVal + x;
                runningSum += currentValue;
                previousVal = currentValue;
            } else{
                currentValue = previousVal - y; 
                runningSum += currentValue;
                previousVal = currentValue;
            }
            
        }

        printf("%lld\n", runningSum);
    }
}