//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  
    int ans = 0;
    int n, m;
  
    bool check(int i, int j)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
  
    void func(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        if(vis[i][j]) return ;
        
        vis[i][j]++;
        
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
        
        for(int it=0; it<8; it++)
        {
            int x = i+dx[it];
            int y = j+dy[it];
            if(check(x, y)) if(grid[x][y] == '1') if(!vis[x][y]) func(x, y, grid, vis);
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        n = grid.size();
        m = grid[0].size();
        
        vector <vector <int>> vis (n, vector <int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    ans++;
                    func(i, j, grid, vis);
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends