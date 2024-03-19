#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* Travelling Sales Person
There are 𝑛 cities numbered from 1 to 𝑛, and city 𝑖 has beauty 𝑎𝑖.

A salesman wants to start at city 1, visit every city exactly once, and return to city 1.

For all 𝑖≠𝑗, a flight from city 𝑖 to city 𝑗 costs max(𝑐𝑖,𝑎𝑗−𝑎𝑖) dollars, where 𝑐𝑖 is the price floor enforced by city 𝑖. 
Note that there is no absolute value. Find the minimum total cost for the salesman to complete his trip.

Input: The first line contains a single integer 𝑛 (2≤𝑛≤10^5) — the number of cities.

The 𝑖-th of the next 𝑛 lines contains two integers 𝑎𝑖, 𝑐𝑖 (0≤𝑎𝑖,𝑐𝑖≤10^9) — the beauty and price floor of the 𝑖-th city.

Output: Output a single integer — the minimum total cost.
*/

vector< vector<ll> > dp(16, vector<ll>(2*1e5+1)); 
ll numCities;
int tsp(vector< vector<ll> > &costs, ll &mx, ll current, ll state){
    if(dp[current][state] > 0) return dp[current][state];
    if(state == mx) return costs[current][0];    // return home

    ll minleft = pow(2, 32) - 1; 
    ll bit = 2;

    for(int i = 1; i < numCities; i++){
        if((state&bit) == 0){   // city i not visited
            minleft = min(minleft, costs[current][i] + tsp(costs, mx, i, state|bit));
        }
        bit <<= 1;
    }
    return dp[current][state] = minleft;
}

int main(){
    cin >> numCities;

    // retrieve beauty and price floor of each city
    vector< pair<ll, ll> > beautyandfloor(numCities);
    for(ll city = 0; city < numCities; city++){
        ll beauty, pricefloor;
        cin >> beauty >> pricefloor;
        beautyandfloor[city] = make_pair(beauty, pricefloor);
    }

    // form cost matrix to travel from each city to another
    vector< vector<ll> > cost(numCities);
    for(ll i = 0; i < numCities; i++){
        for(ll j = 0; j < numCities; j++){
            cost[i].push_back(max(beautyandfloor[i].second, beautyandfloor[j].first - beautyandfloor[i].first));
        }
    }

    ll mx = (1 << numCities) - 1;
    cout << tsp(cost, mx, 0, 1) << endl;
}