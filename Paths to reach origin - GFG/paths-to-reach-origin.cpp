//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

int dp[505][505];

int mod = 1000000007;

    
    int func(int x, int y)
    {
        //returns the num of ways
        //to go from (x, y) -> (0, 0)
        
        if(x == 0 or y == 0) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        return dp[x][y] = (func(x-1, y) + func(x, y-1))%mod;
    }

    int ways(int x, int y)
    {
        //code here.
        
        for(int i=0; i<505; i++)
        {
            for(int j=0; j<505; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        return func(x, y)%mod;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends