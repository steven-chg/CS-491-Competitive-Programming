#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Lucky Division
Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the 
lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. 
Help him find out if the given number n is almost lucky.

Input: The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output: In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
*/

int main(){
    ll n;
    cin >> n;

    // lucky numbers less than 1000 include 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777; therefore, we can hardcode to check if evenly divisible by any of these numbers
    if(n % 4 == 0 || n % 7 == 0 || n % 44 == 0 || n % 47 == 0 || n % 74 == 0 || n % 77 == 0 || n % 444 == 0 || n % 447 == 0 || n % 474 == 0 || n % 477 == 0 || n % 744 == 0 || n % 747 == 0 || n % 774 == 0 || n % 777 == 0){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}