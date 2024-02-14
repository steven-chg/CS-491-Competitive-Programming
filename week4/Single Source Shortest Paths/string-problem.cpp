#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* String Problem
Boy Valera likes strings. And even more he likes them, when they are identical. 
That's why in his spare time Valera plays the following game. He takes any two strings, consisting of lower case Latin letters, 
and tries to make them identical. According to the game rules, with each move Valera can change one arbitrary character Ai in one of the strings 
into arbitrary character Bi, but he has to pay for every move a particular sum of money, equal to Wi. He is allowed to make as many moves as he needs. 
Since Valera is a very economical boy and never wastes his money, he asked you, an experienced programmer, to help him answer the question: 
what minimum amount of money should Valera have to get identical strings.

Input: The first input line contains two initial non-empty strings s and t, consisting of lower case Latin letters. 
The length of each string doesn't exceed 10^5. The following line contains integer n (0 ≤ n ≤ 500) — amount of possible changings. 
Then follow n lines, each containing characters Ai and Bi (lower case Latin letters) and integer Wi (0 ≤ Wi ≤ 100), saying that it's allowed 
to change character Ai into character Bi in any of the strings and spend sum of money Wi.

Output: If the answer exists, output the answer to the problem, and the resulting string. Otherwise output -1 in the only line. 
If the answer is not unique, output any.
*/

/* Possible Test Cases 

1. The input strings are identical (length 1, length > 1) (PASS)
2. Amount of possible changings = 0 (when strings are identical, when strings aren't identical) (PASS)
3. Transitioning from ' ' to a character or vice versa (to transition strings of different lengths); (NOT SUPPORTED)
4. Multiple transformation pairs required
    4.1 A particular transformation doesn't exist (before a transition that does exist, or after a transition that does exist) (PASS)
    4.2 None of the required transformations required exist (PASS)
5. Single transformation pair required (test at all indices of the string)
    5.1 Specific transformation doesn't exist but there are possible changings (PASS)
    5.2 Specific transformation doesn't exist, and there are 0 possible changings (PASS)
    5.3 Direct transformation doesn't exist, but there are sequences of transitions (2, 3, 4, or more, etc.) (PASS)
    5.4 Direct transformation exists, and there are also other possible changings (that do not apply) OR there are no other changings (possible changings = 1) (PASS)
*/

// define graph structure
struct Edge{
    char destination;
    ll weight;
};

typedef map< char, vector<Edge> > graph;

// dijkstra's algorithm function; return -1 if there is no path from source to destination
ll dijkstra(graph graphStructure, char source, char destination){
    // cout << "dijkstra source " << source << " destination " << destination << endl;
    // declare map to track distance from source (initialize distance from source to source to 0)
    map<char, ll> distance;
    distance[source] = 0;

    // declare priority queue and insert the source and its distance from source (which is 0)
    priority_queue< pair<ll, char>, vector< pair<ll, char> >, greater< pair<ll, char> > > queue;
    queue.push(make_pair(0, source));

    // initialize distance from source to every other node to a large value 
    for(auto &charEdge : graphStructure){
        if(charEdge.first != source) distance[charEdge.first] = 1e5;
        for(auto &destination : charEdge.second){
            if(destination.destination != source) distance[destination.destination] = 1e5;
        }
    }

    // if the destination node doesn't exist, then return -1
    if(distance.find(destination) == distance.end()) return -1;

    while(!queue.empty()){
        // get the shortest unvisited vertex 
        ll newDistance = queue.top().first;
        char node = queue.top().second;
        queue.pop();
  
        if(newDistance > distance[node]) continue;

        // iterate over neighbors of the current node
        if(graphStructure.find(node) != graphStructure.end()){
            for(const Edge& edge : graphStructure.at(node)){
                char destination = edge.destination;
                ll weight = edge.weight;
                if(distance[node] + weight < distance[destination]){
                    distance[destination] = distance[node] + weight;
                    queue.push(make_pair(distance[destination], destination));
                }
            }
        }
    }

    if(distance[destination] == 1e5){
        return -1;
    } else{
        return distance[destination];
    }
}

int main(){
    // retrieve the two strings
    string stringOne, stringTwo;
    cin >> stringOne;
    cin >> stringTwo;

    // if the string lengths are different, then return -1 (impossible)
    if(stringOne.size() != stringTwo.size()){
        cout << -1 << endl;
        return 0;
    }

    // declare a vector to track the final string (initialize to '0')
    vector<char> finalString(stringOne.size(), '0');
    vector<ll> missingCharIndex;

    // declare a vector to store pairs of characters that need to be transformed
    vector< pair<char, char> > characterPairs;

    // otherwise, loop through every single character in the string
    for(ll characterNum = 0; characterNum < stringOne.size(); characterNum++){
        // if the characters agree, then insert it into the finalString
        if(stringOne[characterNum] == stringTwo[characterNum]) finalString[characterNum] = stringOne[characterNum];
        // if the characters don't agree, then we leave the field as '0' and store the pair; also store the index into finalString
        else{
            characterPairs.push_back(make_pair(stringOne[characterNum], stringTwo[characterNum]));
            missingCharIndex.push_back(characterNum);
        }
    }

    // now characterPairs includes all character pairs that need to be transformed

    // retrieve the edges and form the graph structure
    graph graphStructure;
    ll numChangings;
    scanf("%lld", &numChangings);
    for(ll changeNum = 0; changeNum < numChangings; changeNum++){
        char to, from; ll weight;
        cin >> from >> to >> weight;
        Edge currentEdge = {to, weight};
        graphStructure[from].push_back(currentEdge);
    }

    // now graphStructure contains mappings from each node to its neighbors (and weights) 
    // (i.e. graphStructure['a'] returns a vector of edges that indicate destination and weight)

    /* VERIFIED characterPairs and graphStructures stores what we want */

    ll totalCost = 0;
    // we need to perform dijkstra's characterPairs.size()*2 times (use a double for loop)
    // (characterPairs.size() is the number of pairs of unmatching characters; need to times 2 because we can change from char a to b or char b to a given a and b don't match)
    for(ll iteration = 0; iteration < characterPairs.size(); iteration++){
        ll leastCostCurrentPair = -1;
        char currentPairResultChar;
        for(ll i = 0; i < 2; i++){
            char source, destination;
            if(i == 0){
                source = characterPairs[iteration].first;
                destination = characterPairs[iteration].second;
            } else if(i == 1){
                source = characterPairs[iteration].second;
                destination = characterPairs[iteration].first;
            }

            // cout << "source " << source << " destination " << destination << endl;

            // perform dijkstra's algorithm to find shortest path between each pair of characters (source and destination)
            ll currentCost = dijkstra(graphStructure, source, destination);

            // cout << " working on pair " << iteration << " attempt " << i << " cost " << currentCost << endl;

            // update the minimum cost for transformation of current pair of characters (also update the resulting character)
            // found the first possible path
            if(leastCostCurrentPair == -1 && currentCost >= 0){
                leastCostCurrentPair = currentCost;
                currentPairResultChar = destination;
            // if there already exists a possible path, but there is a better path in the opposite direction
            } else if(leastCostCurrentPair >= 0 && currentCost != -1 && currentCost < leastCostCurrentPair){
                leastCostCurrentPair = currentCost;
                currentPairResultChar = destination;
            }

        }

        // if this current pair of characters cannot be transformed to each other, then it is impossible to get 2 identical strings
        if(leastCostCurrentPair == -1){
            cout << -1 << endl;
            return 0;
        }
        // otherwise, add to running sum of total cost
        totalCost += leastCostCurrentPair;
        // store the resulting character into the final string
        finalString[missingCharIndex[iteration]] = currentPairResultChar;

    }

    // print total cost and the final string
    cout << totalCost << endl;
    for(ll charNum = 0; charNum < stringOne.size(); charNum++){
        cout << finalString[charNum];
    }
    cout << endl;

}