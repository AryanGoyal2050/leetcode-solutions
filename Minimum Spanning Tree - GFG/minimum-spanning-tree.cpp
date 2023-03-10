//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue <pair <int, pair <int, int>>> pq;    //<-weight, <node, parent>>
        vector <int> vis (V, 0);
        
        pq.push({-0, {0, -1}});  //note -ve of weight
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second.first;
            int parent = it.second.second;
            int w = -it.first;
            
            if(vis[node]) continue;
            vis[node]++;
            sum += w;
            
            for(auto it : adj[node])
            {
                int newNode = it[0];
                int parent = node;
                int newW = it[1];
                if(!vis[newNode])
                {
                    pq.push({-newW, {newNode, parent}});
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends