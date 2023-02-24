//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    int vis[100005] = {0};
    int pathVis[100005] = {0};
  
    bool dfs(int x, vector <int> adj[])
    {
        vis[x] = 1;
        pathVis[x] = 1;
        
        for(auto it : adj[x])
        {
            if(vis[it])
            {
                if(pathVis[it]) return true;
                else continue;
            }
            else if(dfs(it, adj)) return true;
        }
        
        pathVis[x] = 0;
        return false;
    }
    
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        for(int i=0; i<V; i++)
        {
            if(vis[i]) continue;
            if(dfs(i, adj)) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends