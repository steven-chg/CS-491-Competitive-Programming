#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Basketball Exercise
Finally, a basketball court has been opened in SIS, so Demid has decided to hold a basketball exercise session. 2⋅𝑛
students have come to Demid's exercise session, and he lined up them into two rows of the same size 
(there are exactly 𝑛 people in each row). Students are numbered from 1 to 𝑛 in each row in order from left to right.

Now Demid wants to choose a team to play basketball. He will choose players from left to right, and the index of 
each chosen player (excluding the first one taken) will be strictly greater than the index of the previously chosen 
player. To avoid giving preference to one of the rows, Demid chooses students in such a way that no consecutive 
chosen students belong to the same row. The first student can be chosen among all 2𝑛 students 
(there are no additional constraints), and a team can consist of any number of students.

Demid thinks, that in order to compose a perfect team, he should choose students in such a way, that the total 
height of all chosen students is maximum possible. Help Demid to find the maximum possible total height of players 
in a team he can choose.

Input: The first line of the input contains a single integer 𝑛 (1≤𝑛≤10^5) — the number of students in each row.

The second line of the input contains 𝑛 integers ℎ1,1,ℎ1,2,…,ℎ1,𝑛 (1≤ℎ1,𝑖≤10^9), where ℎ1,𝑖 is the height of the 𝑖-th 
student in the first row.

The third line of the input contains 𝑛 integers ℎ2,1,ℎ2,2,…,ℎ2,𝑛 (1≤ℎ2,𝑖≤10^9), where ℎ2,𝑖 is the height of the 𝑖-th 
student in the second row.

Output: Print a single integer — the maximum possible total height of players in a team Demid can choose.
*/

int main(){
    ll studentsPerRow;
    cin >> studentsPerRow;

    vector<ll> firstRow(studentsPerRow);
    vector<ll> secondRow(studentsPerRow);

    // retrieve the rows of students and their height
    for(int row = 0; row < 2; row++){
        for(int student = 0; student < studentsPerRow; student++){
            if(row == 0) cin >> firstRow[student];
            if(row == 1) cin >> secondRow[student];
        }
    }

    // find the maximum height possible column by column; starting from the second column (second player in each row)
    for(int i = 1; i < studentsPerRow; i++){
        // work on first row
        firstRow[i] = max(firstRow[i-1], secondRow[i-1] + firstRow[i]);
        // work on second row
        secondRow[i] = max(secondRow[i-1], firstRow[i-1] + secondRow[i]);
    }

    cout << max(firstRow[studentsPerRow - 1], secondRow[studentsPerRow - 1]) << endl;
}