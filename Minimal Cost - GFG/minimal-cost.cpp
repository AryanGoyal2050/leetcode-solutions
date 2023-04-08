//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int dp[100005];
    
    int func(vector<int>& height, int i, int n, int k)
    {
        //return the min cost
        //to reach n from i
        
        if(i == n) return 0;
        int ans = INT_MAX;
        
        if(dp[i] != -1) return dp[i];
        
        for(int j=1; j<=k; j++)
        {
            if(i+j <= n) ans = min(ans, abs(height[i]-height[i+j]) + func(height, i+j, n, k));
        }
        
        return dp[i] = ans;
        
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        for(int i=0; i<100005; i++)
        {
            dp[i] = -1;
        }
        
        return func(height, 0, n-1, k);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends