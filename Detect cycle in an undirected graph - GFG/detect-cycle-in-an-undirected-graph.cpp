//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    int ans = 0;
    
    int vis[100005] = {0};
    
    bool func(int x, int par, vector <int> adj[])
    {
        vis[x] = 1;
        
        for(auto it : adj[x])
        {
            if(it == par) continue;   //parent
            if(vis[it]) return true;
            if(func(it, x, adj)) return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        for(int i=0; i<V; i++)
        {
            if(vis[i]) continue;
            if(func(i, -1, adj)) return true;
        }
        
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends