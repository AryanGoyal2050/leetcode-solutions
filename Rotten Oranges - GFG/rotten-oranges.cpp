//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        //use bfs
        //need to move level wise
        int ans = 0;
        queue <pair < pair<int, int>, int>> q;  //<location, num of moves>
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int>> vis (n, vector <int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j]++;
                }
            }
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int num = it.second;
            
            ans = max(ans, num);
            
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            
            for(int i=0; i<4; i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx >= 0 and newy >= 0 and newx < n and newy < m)
                    if(!vis[newx][newy])
                        if(grid[newx][newy] == 1)
                        {
                            q.push({{newx, newy}, num+1});
                            vis[newx][newy]++;
                        }
            }
        }
        
        int check = 0;  //checking for edge case of NOT POSSIBLE TO ROTTEN ALL ORANGES
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 and vis[i][j] == 0) check++;
            }
        }
        
        if(check) return -1;
        
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends