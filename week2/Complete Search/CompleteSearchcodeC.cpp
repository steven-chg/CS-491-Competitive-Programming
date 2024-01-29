#include <bits/stdc++.h>

using namespace std;

/* Groups
𝑛 students attended the first meeting of the Berland SU programming course (𝑛 is even). All students will be divided into two groups. 
Each group will be attending exactly one lesson each week during one of the five working days (Monday, Tuesday, Wednesday, Thursday and Friday), and the days chosen for the groups 
must be different. Furthermore, both groups should contain the same number of students.

Each student has filled a survey in which they told which days of the week are convenient for them to attend a lesson, and which are not.
Your task is to determine if it is possible to choose two different week days to schedule the lessons for the group (the first group will attend the lesson on the first chosen day, 
the second group will attend the lesson on the second chosen day), and divide the students into two groups, so the groups have equal sizes, and for each student, the chosen lesson day 
for their group is convenient.

Input: The first line contains a single integer 𝑡 (1≤𝑡≤10^4) — the number of testcases.
Then the descriptions of 𝑡 testcases follow.
    The first line of each testcase contains one integer 𝑛 (2≤𝑛≤1000) — the number of students.
    The 𝑖-th of the next 𝑛 lines contains 5 integers, each of them is 0 or 1. If the 𝑗-th integer is 1, then the 𝑖-th student can attend the lessons on the 𝑗-th day of the week. 
    If the 𝑗-th integer is 0, then the i-th student cannot attend the lessons on the 𝑗-th day of the week.

Additional constraints on the input: for each student, at least one of the days of the week is convenient, the total number of students over all testcases doesn't exceed 10^5.

Output: For each testcase print an answer.
If it's possible to divide the students into two groups of equal sizes and choose different days for the groups so each student can attend the lesson in the chosen day of their group, 
print "YES" (without quotes). Otherwise, print "NO" (without quotes).
*/

int main(){
    // retrieve number of test cases and loop for that amount of times
    long long int numCases;
    cin >> numCases;
    for(long long int testCase = 0; testCase < numCases; testCase++){

        // get the  number of students in each test case
        int numStudents;
        cin >> numStudents;

        // create a 2D vector to track availability of students
        vector< vector<int> > studentAvailability(numStudents);

        // fill in the 2D vector to track availability of every single student
        for(int students = 0; students < numStudents; students++){
            // get the availability of the current student
            int M, T, W, Th, F;
            cin >> M >> T >> W >> Th >> F;
            // insert all M-F availability into the vector
            studentAvailability[students].push_back(M);
            studentAvailability[students].push_back(T);
            studentAvailability[students].push_back(W);
            studentAvailability[students].push_back(Th);
            studentAvailability[students].push_back(F);
        }

                
        // declare and initialize a flag to indicate whether there is a possible combination for this current test case
        int flag = 0;

        // loop through all combination of 2 day classes (0 represents Monday, and so on)
        for (int classOne = 0; classOne < 5; classOne++){
            for (int classTwo = classOne + 1; classTwo < 5; classTwo++){

                // declare variables to track number of students who are STRICTLY available for each of the 2 days, and num students available both days
                int numAvailableClassOneStrictly = 0; int numAvailableClassTwoStrictly = 0; int numAvailableBothClass = 0;

                // loop through all students and count their availability 
                for(int student = 0; student < numStudents; student++){
                    // if they are available both days
                    if(studentAvailability[student][classOne] == 1 && studentAvailability[student][classTwo] == 1){
                        numAvailableBothClass += 1;
                    } else if(studentAvailability[student][classOne] == 1){
                    // if they are available on classOne day only
                        numAvailableClassOneStrictly += 1;
                    } else if(studentAvailability[student][classTwo] == 1){
                    // if they are available on classTwo day only
                        numAvailableClassTwoStrictly += 1;
                    }
                }

                // check if number of students that are available on one date or both dates is equal to total number of students
                if((numAvailableBothClass + numAvailableClassOneStrictly + numAvailableClassTwoStrictly) == numStudents){
                    // if we put all students who are available both days to the class that has less people and that number is still lower than the other class, it is not possible; continue to next combination of days
                    if((numAvailableClassOneStrictly > numAvailableClassTwoStrictly) && ((numAvailableClassTwoStrictly + numAvailableBothClass) < numAvailableClassOneStrictly)){
                        continue;
                    } else if((numAvailableClassTwoStrictly > numAvailableClassOneStrictly) && ((numAvailableClassOneStrictly + numAvailableBothClass) < numAvailableClassTwoStrictly)){
                        continue;
                    } else{ // if the two classes have even number of people already or if we can distribute the students available both days to make it even class size
                        // print "YES" and update flag
                        printf("YES\n");
                        flag = 1;
                    }
                }

                // if already success, break out of inner for loop
                if(flag){
                    break;
                }

            }
            // if already success, break out of outer for loop
            if(flag){
                break;
            }
        }

        // if none of the combinations of days yielded success, then print "NO"
        if(flag == 0){
            printf("NO\n");
        }
    }
}