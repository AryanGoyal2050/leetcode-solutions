//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int dp[10005];
    
    int func(int arr[], int ind, int n)
    {
        //max loot form houses
        //of indices >= ind
        
        if(ind >= n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        return dp[ind] = max(func(arr, ind+1, n), arr[ind] + func(arr, ind+2, n));
        
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        memset(dp, -1, sizeof(dp));
        
        return func(arr, 0, n);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends