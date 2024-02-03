#include <bits/stdc++.h>

using namespace std;

/* Secret Passwords
One unknown hacker wants to get the admin's password of AtForces testing system, to get problems from the next contest. 
To achieve that, he sneaked into the administrator's office and stole a piece of paper with a list of 𝑛 passwords — strings, 
consists of small Latin letters.

Hacker went home and started preparing to hack AtForces. He found that the system contains only passwords from the stolen list and that the 
system determines the equivalence of the passwords 𝑎 and 𝑏 as follows:
    two passwords 𝑎 and 𝑏 are equivalent if there is a letter, that exists in both 𝑎 and 𝑏;
    two passwords 𝑎 and 𝑏 are equivalent if there is a password 𝑐 from the list, which is equivalent to both 𝑎 and 𝑏.

If a password is set in the system and an equivalent one is applied to access the system, then the user is accessed into the system.
For example, if the list contain passwords "a", "b", "ab", "d", then passwords "a", "b", "ab" are equivalent to each other, 
but the password "d" is not equivalent to any other password from list. In other words, if:
    admin's password is "b", then you can access to system by using any of this passwords: "a", "b", "ab";
    admin's password is "d", then you can access to system by using only "d".
Only one password from the list is the admin's password from the testing system. 
Help hacker to calculate the minimal number of passwords, required to guaranteed access to the system. 
Keep in mind that the hacker does not know which password is set in the system.

Input: The first line contain integer 𝑛 (1≤𝑛≤2⋅10^5) — number of passwords in the list. Next 𝑛 lines contains passwords from the list 
– non-empty strings 𝑠𝑖, with length at most 50 letters. Some of the passwords may be equal.

It is guaranteed that the total length of all passwords does not exceed 10^6 letters. All of them consist only of lowercase Latin letters.

Output: In a single line print the minimal number of passwords, the use of which will allow guaranteed to access the system.
*/

int main(){

    

}

