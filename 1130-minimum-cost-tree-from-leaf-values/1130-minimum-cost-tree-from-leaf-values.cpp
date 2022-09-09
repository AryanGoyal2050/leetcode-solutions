class Solution {
private:
    
    int func(int i, int j, vector<int>& arr, map <pair <int, int>, int> & m, vector <vector <int>> & dp)
    {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int x = i; x < j; x++)
        {
            int curr = func(i, x, arr, m, dp) + func(x+1, j, arr, m, dp) + m[{i, x}]*m[{x+1, j}];
            ans = min(ans, curr);
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        map <pair <int, int>, int> m;   //map : {i, j} -> max
        int n = arr.size();
        vector <vector <int>> dp(n+1, vector <int> (n+1, -1));
        for(int i=0; i<n; i++)
        {
            int maxi = arr[i];
            for(int j=i; j<n; j++)
            {
                maxi = max(maxi, arr[j]);
                m[{i, j}] = maxi;
            }
        }
        
        return func(0, n-1, arr, m, dp);
        
    }
};
