//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int dp[100005];
  
  int func(vector <int> & height, int n, int dp[])
  {
      //min energy reqd
      //to go from n->0
      
      if(n == 0) return 0;
      
      if(dp[n] != -1) return dp[n];
      
      int ans = INT_MAX;
      
      if(n-1 >= 0) ans = min(ans, abs(height[n]-height[n-1]) + func(height, n-1, dp));
      if(n-2 >= 0) ans = min(ans, abs(height[n]-height[n-2]) + func(height, n-2, dp));
      
      return dp[n] = ans;
      
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        for(int i=0; i<100005; i++)
        {
            dp[i] = -1;
        }
        
        return func(height, n-1, dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends