//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[1005][805];
    int mod = 1000000007;
    
    int func(int n, int r)
    {
        if(n<0 or r<0 or n<r) return 0;
        
        if(dp[n][r] != -1) return dp[n][r];
        
        if(r == 1 or r == n-1) return dp[n][r] = n;
        if(r == 0 or r == n) return dp[n][r] = 1;
        
        return dp[n][r] = (func(n-1, r) + func(n-1, r-1))%mod;
        
    }

    int nCr(int n, int r){
        // code here
        
        for(int i=0; i<1005; i++){
            for(int j=0; j<805; j++){
                dp[i][j] = -1;
            }
        }
        
        return func(n, r)%mod;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends