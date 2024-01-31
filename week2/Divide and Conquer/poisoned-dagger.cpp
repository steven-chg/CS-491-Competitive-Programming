#include <bits/stdc++.h>

using namespace std;

/* Poisoned Dagger
Monocarp is playing yet another computer game. In this game, his character has to kill a dragon. The battle with the dragon lasts 100^500 seconds, during which Monocarp 
attacks the dragon with a poisoned dagger. The 𝑖-th attack is performed at the beginning of the 𝑎𝑖-th second from the battle start. 
The dagger itself does not deal damage, but it applies a poison effect on the dragon, which deals 1 damage during each of the next 𝑘 seconds 
(starting with the same second when the dragon was stabbed by the dagger). However, if the dragon has already been poisoned, then the dagger updates the poison effect 
(i.e. cancels the current poison effect and applies a new one).

For example, suppose 𝑘=4, and Monocarp stabs the dragon during the seconds 2, 4 and 10. Then the poison effect is applied at the start of the 2-nd second and deals 1
damage during the 2-nd and 3-rd seconds; then, at the beginning of the 4-th second, the poison effect is reapplied, so it deals exactly 1 damage during the seconds 4, 5, 6 and 7
; then, during the 10-th second, the poison effect is applied again, and it deals 1 damage during the seconds 10, 11, 12 and 13. In total, the dragon receives 10 damage.

Monocarp knows that the dragon has ℎ hit points, and if he deals at least ℎ damage to the dragon during the battle — he slays the dragon. 
Monocarp has not decided on the strength of the poison he will use during the battle, so he wants to find the minimum possible value of 𝑘 (the number of seconds the poison effect lasts) 
that is enough to deal at least ℎ damage to the dragon.

Input: The first line contains a single integer 𝑡 (1≤𝑡≤1000) — the number of test cases.
The first line of the test case contains two integers 𝑛 and ℎ (1≤𝑛≤100;1≤ℎ≤10^18) — the number of Monocarp's attacks and the amount of damage that needs to be dealt.
The second line contains 𝑛 integers 𝑎1, 𝑎2, ..., 𝑎𝑛 (1≤𝑎𝑖≤10^9;𝑎𝑖<𝑎𝑖+1), where 𝑎𝑖 is the second when the 𝑖-th attack is performed.

Output: For each test case, print a single integer — the minimum value of the parameter 𝑘, such that Monocarp will cause at least ℎ damage to the dragon.
*/

int main(){
    // retrieve the number of test cases and loop for the number of test case
    int numCases;
    cin >> numCases;
    for(int caseNum = 0; caseNum < numCases; caseNum++){
        // retrieve then number of Monocarp's attacks and the amount of damage that needs to be dealt
        int numAttacks; long long int damageRequired;
        cin >> numAttacks >> damageRequired;

        // declare a vector to store the number of seconds since the previous attack (damagePerformed[2] stores # of seconds since the 1st attack or # of seconds for 1st attack to poison)
        vector<long long int> damagePerformed(numAttacks+1, 0);
        long long int previousAttackTime = 0; long long int currentAttackTime;
        for(int attackNum = 1; attackNum <= numAttacks; attackNum++){
            cin >> currentAttackTime;
            damagePerformed[attackNum] = currentAttackTime - previousAttackTime;
            previousAttackTime = currentAttackTime;
        }
        // set the first index position to value 0 since there is no attack before the first attack
        damagePerformed[1] = 0;

        // check if k = 1 will satisfy damage required
        if(numAttacks >= damageRequired){
            cout << 1 << "\n";
            continue;
        }

        // initialize a variable to track totalDamage for each kEstimate, initialized to 0
        long long int totalDamage = 0;

        // begin with kEstimate = damageRequired/numAttacks rounded up (this is the minimum kEstimate if all attacks can persist for kEstimate time)
        long long int kEstimate = (damageRequired + numAttacks - 1)/numAttacks;

        // loop through all the attacks (except last attack) and check how long they persist (starting with index 2 since index 2 stores how long 1st attack lasts)
        for(int attack = 2; attack <= numAttacks; attack++){
            if(damagePerformed[attack] >= kEstimate){
                totalDamage += kEstimate;
            } else{
                totalDamage += damagePerformed[attack];
            }
        }
        // the last attack will always last for kEstimate time 
        totalDamage += kEstimate;

        while(totalDamage < damageRequired){
            // get the new kEstimate (find how many attacks more is needed assuming that all attacks can last for the same amount longer; this is the minimum new kEstimate)
            kEstimate += (damageRequired - totalDamage + numAttacks - 1)/numAttacks;

            // reset totalDamage to 0 and then go through the loop to get the new kEstimate
            totalDamage = 0;

            // loop through all the attacks (except last attack) and check how long they persist (starting with index 2 since index 2 stores how long 1st attack lasts)
            for(int attack = 2; attack <= numAttacks; attack++){
                if(damagePerformed[attack] >= kEstimate){
                    totalDamage += kEstimate;
                } else{
                    totalDamage += damagePerformed[attack];
                }
            }
            // the last attack will always last for kEstimate time 
            totalDamage += kEstimate;
        }            

        cout << kEstimate << "\n";
    }
}

/* NON OPTIMIZED VERSION */
// int main(){
//     // retrieve the number of test cases and loop for the number of test case
//     int numCases;
//     cin >> numCases;
//     for(int caseNum = 0; caseNum < numCases; caseNum++){
//         // retrieve then number of Monocarp's attacks and the amount of damage that needs to be dealt
//         int numAttacks; long long int damageRequired;
//         cin >> numAttacks >> damageRequired;
 
//         // declare a vector to store the number of seconds since the previous attack (damagePerformed[2] stores # of seconds since the 1st attack or # of seconds for 1st attack to poison)
//         vector<long long int> damagePerformed(numAttacks+1, 0);
 
//         // first store the time each attack occurs
//         for(int attackNum = 1; attackNum <= numAttacks; attackNum++){
//             cin >> damagePerformed[attackNum];
//         }
//         // then loop from the back of the vector and subtract by previous index value to store the number of seconds the previous attack can run before current attack 
//         // (effectively index 2 to numAttacks is useful to track number of seconds the 1st attack to second to last attack can run for)
//         for(int attackNum = numAttacks; attackNum >= 1; attackNum--){
//             damagePerformed[attackNum] -= damagePerformed[attackNum - 1];
//         }
 
//         // set the first index position to value 0 since there is no attack before the first attack
//         damagePerformed[1] = 0;
 
//         // initialize total damage to assume kEstimate is 1 initially
//         long long int totalDamage = numAttacks;
//         int attacksPersisting = numAttacks;
 
//         // check if k = 1 will satisfy damage required
//         if(totalDamage >= damageRequired){
//             cout << 1 << "\n";
//             continue;
//         }
 
//         // else loop and continue checking by incrementing k each time (starting from 2)
//         for(long long int kEstimate = 2; ;kEstimate++){
//             // update total damage by adding the total number of attacks by the number of attacks that only last kEstimate - 1 seconds
//             totalDamage += (attacksPersisting - count(damagePerformed.begin(), damagePerformed.end(), kEstimate - 1));
//             attacksPersisting -= count(damagePerformed.begin(), damagePerformed.end(), kEstimate - 1);
//             if(totalDamage >= damageRequired){
//                 // print out the minimum k required and break to next test case
//                 cout << kEstimate << "\n";
//                 break;
//             }
//         }
//     }
// }