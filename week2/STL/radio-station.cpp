#include <bits/stdc++.h>

using namespace std;

/* Radio Station
Each ip is of form "a.b.c.d" where a, b, c and d are non-negative integers less than or equal to 255 (with no leading zeros). 
The nginx configuration file Dustin has to add comments to has m commands. Nobody ever memorizes the ips of servers, so to understand the configuration better, 
Dustin has to comment the name of server that the ip belongs to at the end of each line (after each command). More formally, if a line is "command ip;" Dustin has 
to replace it with "command ip; #name" where name is the name of the server with ip equal to ip.
Dustin doesn't know anything about nginx, so he panicked again and his friends asked you to do his task for him.

Input: The first line of input contains two integers n and m (1 ≤ n, m ≤ 1000).
The next n lines contain the names and ips of the servers. Each line contains a string name, name of the server and a string ip, ip of the server, 
separated by space (1 ≤ |name| ≤ 10, name only consists of English lowercase letters). It is guaranteed that all ip are distinct.
The next m lines contain the commands in the configuration file. Each line is of form "command ip;" (1 ≤ |command| ≤ 10, command only consists of 
English lowercase letters). It is guaranteed that ip belongs to one of the n school servers.

Output: Print m lines, the commands in the configuration file after Dustin did his task.
*/

int main(){

    // Get the number of servers involved and the number of commands
    int numServers, numCommands;
    scanf("%d %d", &numServers, &numCommands);

    // Declare variable for server name and IP address
    string name, IP, command;

    // Declare map for hashing 
    map<string, string> serversIP;

    // Map the name of the server to its IP address
    while(numServers > 0){
        // Retrieve name and IP of the server 
        cin >> name >> IP;
        // Add semicolon to end of IP address
        IP = IP.append(";");
        // Map name to specific IP address
        serversIP[IP] = name;
        // Decrement number of servers 
        numServers--;
    }

    // Print out the commands with the names of the server
    while(numCommands > 0){
        // Retrieve the command and IP of server
        cin >> command >> IP;
        // Get the name of the server
        name = serversIP[IP];
        // Print the command with server name
        cout << command << " " << IP << " #" << name << endl;
        // Decrement number of commands
        numCommands--;
    }
    return 0;
}