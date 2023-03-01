//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        
        queue <pair <pair<int, int>, int>> q;    // <location, moves>
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        
        vector <vector <int>> vis (N+1, vector <int> (N+1, 0)); // visited vector
        int ans = INT_MAX;
        
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int mov = temp.second;
            if(vis[x][y])continue;
            
            
            if(x == TargetPos[0] and y == TargetPos[1])  return mov;
            
            for(int i=0; i<8; i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx > 0 and newy > 0 and newx <= N and newy <= N){
                      if(!vis[newx][newy]) {
                          q.push({{newx, newy}, mov+1});
                          vis[x][y]++;
                      }
                }
            }
        }
        
        return -1;
	
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends