// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
int dp[100005];
class Solution{
  public:
  
    int func(int price[], int n) {
        //returns the max price we can get
        //from a rod of length n
        
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(i+1 > n) continue;
            ans = max(ans, price[i] + func(price, n-(i+1)));
        }
        
        return dp[n] = ans;
    }
    
    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return func(price, n);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends