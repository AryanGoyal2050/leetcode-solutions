//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int func(vector<vector<int>> & grid,  vector <vector <vector <int>>> & dp, int d, int i, int j)
    {
        //robot1 @ (d, i)
        //robot2 @ (d, j)
        //max num of chocolates we can collect
        //from levels of index >= d
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(d >= n) return 0;
        if(i < 0 or i >= m) return 0;
        if(j < 0 or j >= m) return 0;
        
        if(dp[d][i][j] != -1) return dp[d][i][j];
        
        int ans = INT_MIN;
        
        for(int di=-1; di<=1; di++)
        {
            for(int dj=-1; dj<=1; dj++)
            {
                ans = max(ans, func(grid, dp, d+1, i+di, j+dj));
            }
        }
        
        if(i == j) ans += grid[d][i];
        else ans += grid[d][i] + grid[d][j];
        
        return dp[d][i][j] = ans;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        vector <vector <vector <int>>> dp(n+1, vector <vector <int>> (m+1, vector <int> (m+1, -1)));
        
        return func(grid, dp, 0, 0, m-1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends