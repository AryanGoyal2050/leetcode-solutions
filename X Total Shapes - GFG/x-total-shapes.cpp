//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int ans = 0;
    int vis[105][105];
    int n, m;
    
    void func(int x, int y, vector<vector<char>>& grid)
    {
        if(vis[x][y]) return ;
        vis[x][y]++;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        for(int i=0; i<4; i++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(newx>=0 and newy>=0 and newx<n and newy<m)
                if(!vis[newx][newy])
                    if(grid[newx][newy] == 'X')
                        func(newx, newy, grid);
        }
    }
    
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        //similar to number of islands
        
        ans = 0;
        
        for(int i=0; i<105; i++)
        {
            for(int j=0; j<105; j++)
            {
                vis[i][j] = 0;
            }
        }
        
        
        
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j] == 'X')
                {
                    // cout<<i<<" "<<j<<endl;
                    func(i, j, grid);
                    ans++;
                    // cout<<"ans = "<<ans<<endl;
                }
            }
        }
        
        return ans;
        
    }
    
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends