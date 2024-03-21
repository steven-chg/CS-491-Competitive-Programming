#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* String Matching
Given two strings 𝑠 and 𝑡, determine the number of times 𝑡 occurs in 𝑠.

Input: The first line contains 𝑠, the second line contains 𝑡. The lines consist only of capital Latin letters, and 1≤|𝑠|,|𝑡|≤300000.

Output: Output the number of times 𝑡 occurs in 𝑠.
*/

int main(){
    string original, desired;
    cin >> original;
    cin >> desired;

    // sanity check, if desired string has greater length than original string, then impossible to match
    if(desired.size() > original.size()){
        cout << "0" << endl;
        return 0;
    }

    // rabin-karp algorithm
    int a = 256;
    int b = 100007;
    ll pow = 1;

    int b2 = 167449;
    ll pow2 = 1;

    ll hash_original = 0;
    ll hash_original2 = 0;
    ll hash_desired = 0;
    ll hash_desired2 = 0;
    for(int i = 0; i < desired.size(); i++){
        hash_original = (hash_original*a + original[i]) % b;
        hash_original2 = (hash_original2*a + original[i]) % b2;
        hash_desired = (hash_desired*a + desired[i]) % b;
        hash_desired2 = (hash_desired2*a + desired[i]) % b2;
        if(i != desired.size()-1){
            pow = (pow * a) % b;
            pow2 = (pow2 * a) % b2;
        }
    }

    ll running_sum = 0;
    for(int i = 0; i <= original.size() - desired.size(); i++){
        if(hash_original == hash_desired && hash_original2 == hash_desired2){
            running_sum++;
        }
        // subtract out letter in front
        hash_original = ((b + hash_original) - (original[i] * pow % b)) % b;
        hash_original2 = ((b2 + hash_original2) - (original[i] * pow2 % b2)) % b2;
        hash_original = (hash_original * a) % b;
        hash_original2 = (hash_original2 * a) % b2;
        // add new letter to the end
        hash_original += original[i+desired.size()];
        hash_original2 += original[i+desired.size()];
        // keep modding
        hash_original = hash_original % b;
        hash_original2 = hash_original2 % b2;
    }
    cout << running_sum << endl;
}