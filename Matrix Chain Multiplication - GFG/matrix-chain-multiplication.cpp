//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

private:
int dp[105][105];

int func(int i, int j, int N, int arr[])
{
    //returns the min multiplications req to
    //multiply matrices from i to j
    
    if(i >= j) return 0;
    if(i+1 == j) return 0;
    if(i+2 == j) return arr[i]*arr[i+1]*arr[i+2];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = INT_MAX;
    
    for(int it=i+1; it<=j-1; it++)
    {
        ans = min(ans, arr[i]*arr[it]*arr[j] + func(i, it, N, arr) + func(it, j, N, arr));
    }
    
    return dp[i][j] = ans;
    
    
}

public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        
        return func(0, N-1, N, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends