/*
Count possible ways to construct buildings
MediumAccuracy: 38.53%Submissions: 42K+Points: 4
90% Refund available on all premium courses 
Discover How  

banner
There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

Example 1:

Input: N = 1
Output: 4
Explanation: 
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.
Example 2:

Input: N = 3
Output: 25
Explanation: 
Possible ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space. Pairing up with 
possibilities on the other side of the road,
total possible ways are 25.
Your Task:
You don't need to read or print anything. Your task is to complete the function TotalWays() which takes N as input parameter and returns the total possible ways modulo 109 + 7.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 100000
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod = 1000000007;
	    vector<vector<int>> dp(N+1, vector<int>(2, 1));
	    for(int i=N-1; i >= 0; i--)
	    {
	        dp[i][1] = dp[i+1][0];
	        int make = dp[i+1][1];
	        int nomake = dp[i+1][0];
	        
	        dp[i][0] = (make + nomake) % mod;
	        
	    }
	    return (dp[0][0] * dp[0][0]) % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends