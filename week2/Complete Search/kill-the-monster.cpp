#include <bits/stdc++.h>

using namespace std;

/* Kill the Monster
Monocarp is playing a computer game. In this game, his character fights different monsters.

A fight between a character and a monster goes as follows. Suppose the character initially has health ℎ𝐶 and attack 𝑑𝐶; the monster initially has health ℎ𝑀 and attack 𝑑𝑀. 
The fight consists of several steps:
    the character attacks the monster, decreasing the monster's health by 𝑑𝐶;
    the monster attacks the character, decreasing the character's health by 𝑑𝑀;
    the character attacks the monster, decreasing the monster's health by 𝑑𝐶;
    the monster attacks the character, decreasing the character's health by 𝑑𝑀;
    and so on, until the end of the fight.

The fight ends when someone's health becomes non-positive (i. e. 0 or less). If the monster's health becomes non-positive, the character wins, otherwise the monster wins.

Monocarp's character currently has health equal to ℎ𝐶 and attack equal to 𝑑𝐶. He wants to slay a monster with health equal to ℎ𝑀 and attack equal to 𝑑𝑀. 
Before the fight, Monocarp can spend up to 𝑘 coins to upgrade his character's weapon and/or armor; each upgrade costs exactly one coin, each weapon upgrade increases
the character's attack by 𝑤, and each armor upgrade increases the character's health by 𝑎.

Can Monocarp's character slay the monster if Monocarp spends coins on upgrades optimally?

Input: The first line contains one integer 𝑡 (1≤𝑡≤5⋅10^4) — the number of test cases. Each test case consists of three lines:

The second line contains two integers ℎ𝐶 and 𝑑𝐶 (1≤ℎ𝐶≤10^15; 1≤𝑑𝐶≤10^9) — the character's health and attack;

The third line contains two integers ℎ𝑀 and 𝑑𝑀 (1≤ℎ𝑀≤10^15; 1≤𝑑𝑀≤10^9) — the monster's health and attack;

The fourth line contains three integers 𝑘, 𝑤, and 𝑎 (0≤𝑘≤2⋅10^5; 0≤𝑤≤10^4; 0≤𝑎≤10^10) — the maximum number of coins that Monocarp can spend, 
the amount added to the character's attack with each weapon upgrade, and the amount added to the character's health with each armor upgrade, respectively.

The sum of 𝑘 over all test cases does not exceed 2⋅10^5.

Output: For each test case, print YES if it is possible to slay the monster by optimally choosing the upgrades. Otherwise, print NO.
*/


/*

THINGS TO BE AWARE OF
- due to large input sie, use long long int instead of regular int
*/

// based on character and monster attack and health, return 1 if character can win; otherwise, return 0
int fightResult(long long int cHealth, long long int cAttack, long long int mHealth, long long int mAttack){

    // get the number of attacks for the monster or character to die (add cAttack - 1 to ensure that it rounds up)
    long long int attackstokillMonster = (mHealth + (cAttack - 1)) / cAttack;
    long long int attackstokillCharacter = (cHealth + (mAttack - 1)) / mAttack;

    // if it takes the same number of times (since character attacks first) or less to kill the monster, then character wins
    if(attackstokillMonster <= attackstokillCharacter){
        return 1;
    } else{
        return 0;
    }
}

int main(){

    // retrieve the number of test cases
    long long int numCases;
    cin >> numCases;

    // loop through all of the test cases
    for(long long int testCase = 0; testCase < numCases; testCase++){

        // retrieve inputs for each test case
        long long int cHealth, cAttack, mHealth, mAttack, numCoins, upgradeAttack, upgradeHealth;
        cin >> cHealth >> cAttack;
        cin >> mHealth >> mAttack;
        cin >> numCoins >> upgradeAttack >> upgradeHealth;

        // declare variables
        int winFlag;

        // reset winFlag to 0 at the start of each test case
        winFlag = 0;

        // perform for loop, beginning by assuming all coins spent on attack, then incrementing armor and decrementing attack
        for(long long int coinOnHealth = 0; coinOnHealth <= numCoins; coinOnHealth++){
            long long int coinOnAttack = numCoins - coinOnHealth;

            // call function to find out if the character can win
            if(fightResult((cHealth + coinOnHealth*upgradeHealth), (cAttack + coinOnAttack*upgradeAttack), mHealth, mAttack)){
                // if any upgrade results in the character winning, then print "YES" and break out of current test case
                printf("YES\n");
                winFlag = 1;
                break;
            }
        }

        // if the current test case already outputted "YES", continue to next test case
        if(winFlag == 1){
            continue;
        }
        // if none of the upgrades can let the character win, print "NO"
        printf("NO\n");
    }

    return 0;
}