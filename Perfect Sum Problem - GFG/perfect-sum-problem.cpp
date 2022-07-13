// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
	public:
	
	int mod = 1e9+7;
	
	int func(int nums[], int ind, int target, int n, vector <vector<int>> & dp, int zero[])
    {
        //returns the number of subsets in nums
        //with index >= ind such that
        //sum == target
        if(target == 0) return dp[ind][target] = 1 + zero[ind];
        if(ind >= n) return 0;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int ans = 0;
        ans += func(nums, ind+1, target, n, dp, zero);
        if(nums[ind] <= target) ans += func(nums, ind+1, target-nums[ind], n, dp, zero);
        
        return dp[ind][target] = (ans%mod);
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector <vector <int>> dp(n+1, vector <int>(sum+1, -1));   //vector <ind, target>
	    
	    int zero[n+1]; //contains the number of 0's at and after this index
	    zero[n-1] = (arr[n-1] == 0);
	    zero[n] = 0;
	    for(int i=n-2; i>=0; i--)
	    {
	        zero[i] = zero[i+1] + (arr[i] == 0);
	    }
	    //for(int i=0; i<n; i++)
	    //{
	    //    cout<<zero[i]<<" ";
	    //}
	    //cout<<endl;
	    
        return func(arr, 0, sum, n, dp, zero)%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends