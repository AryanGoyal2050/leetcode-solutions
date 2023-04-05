//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    
    long long int dp[1005][1005];
    
    long long int func(int coins[], int N, int sum, int ind)
    {
        //return the number of ways
        //of representing sum
        //with coins of indices <= ind
        
        if(ind >= N or ind < 0) return 0;
        
        if(dp[sum][ind] != -1) return dp[sum][ind];
        
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        
        long long int ans = 0;
        if(coins[ind] <= sum) ans += func(coins, N, sum-coins[ind], ind);
        ans += func(coins, N, sum, ind-1);
        
        return dp[sum][ind] = ans;
        
    }
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        for(int i=0; i<1005; i++)
        {
            for(int j=0; j<1005; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        return func(coins, N, sum, N-1);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends