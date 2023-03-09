//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector <int>> vis (n, vector <int> (m, 0));
        
        pair <int, int> s, d;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1) s = {i, j};
                if(grid[i][j] == 2) d = {i, j};
            }
        }
        
        queue <pair <int, int>> q;
        q.push(s);
        vis[s.first][s.second]++;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int i=0; i<4; i++)
            {
                int newx = it.first+dx[i];
                int newy = it.second+dy[i];
                
                if(newx>=0 and newy>=0 and newx<n and newy<m)
                    if(grid[newx][newy] != 0)
                        if(!vis[newx][newy])
                        {
                            q.push({newx, newy});
                            vis[newx][newy]++;
                        }
            }
        }
        
        if(vis[d.first][d.second]) return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends