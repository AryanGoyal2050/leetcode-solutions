class Solution {

void func(int i, int j, vector<vector<char>> & grid, vector <vector <int>> & color)
{
    //function to color land staring from (i, j)
    //color with x
    //search for uncoloured in all 4 drections
    
    int m = grid.size();
    int n = grid[0].size();
    
    //////already checked constraints
    if(grid[i][j] == '0') return ;
    if(color[i][j]) return ;
    if(i>=m or i<0 or j>=n or j<0) return ;
    /////////////////////////////////
    
    color[i][j]++;
    
    if(!(i+1>=m or i+1<0 or j>=n or j<0)) if(grid[i+1][j] == '1' and color[i+1][j] == 0) func(i+1, j, grid, color);
    if(!(i>=m or i<0 or j+1>=n or j+1<0)) if(grid[i][j+1] == '1' and color[i][j+1] == 0) func(i, j+1, grid, color);
    if(!(i-1>=m or i-1<0 or j>=n or j<0)) if(grid[i-1][j] == '1' and color[i-1][j] == 0) func(i-1, j, grid, color);
    if(!(i>=m or i<0 or j-1>=n or j-1<0)) if(grid[i][j-1] == '1' and color[i][j-1] == 0) func(i, j-1, grid, color);
    
}

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector <vector <int>> color (m, vector <int> (n, 0));
        
        int ans = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(color[i][j] == 0 and grid[i][j] == '1')
                {
                    ans++;
                    func(i, j, grid, color);
                }
                cout<<color[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return ans;
    }
};
