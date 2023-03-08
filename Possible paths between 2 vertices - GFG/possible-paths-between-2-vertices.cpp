//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

private:

    int vis[100005];
    int pathVis[100005];
    
    int ans;
    
    void dfs(int s, int d, vector <int> adj[])
    {
        if(s == d)
        {
            ans++;
            return ;
        }
        
        if(vis[s]) return ;
        vis[s]++;
        //pathVis[s]++;
        
        for(auto it : adj[s])
        {
            dfs(it, d, adj);
        }
        
        vis[s] = 0;
    }


public:

    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        
        ans = 0;
        
        dfs(source, destination, adj);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends