class Solution {
private:
    
    bool cycle(int i, vector<vector<int>> & adj, vector <int> & visit, vector <int> & selfVisit)
    {
        if(selfVisit[i]) return true;
        
        visit[i] = 1;        
        selfVisit[i] = 1;
        
        for(auto it : adj[i])
        {
            if(!visit[it])
            {
                if(cycle(it, adj, visit, selfVisit)) return true;
            }
            else if(selfVisit[it]) return true;
        }
        
        selfVisit[i] = 0;
        
        return false;
    }
    
    void func(int i, vector<vector<int>> & adj, vector <int> & vis, stack <int> & s)
    {
        vis[i]++;
        for(auto it : adj[i])
        {
            if(!vis[it]) func(it, adj, vis, s);
            
        }
        s.push(i);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector <int> vis(n, 0);
        
        vector <vector <int>> adj(n);
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        //check for cycle
        //if(cycle) return empty vector
        //else proceed
        
        vector <int> visit(n, 0);
        vector <int> selfVisit(n, 0);
        
        int check = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visit[i])
            {
                if(cycle(i, adj, visit, selfVisit)) check++;
            }
                
        }
        
        vector <int> empty;
        
        if(check) return empty;
        
        ////////////////////////////////
        //no cycle detected
        
        vector <int> ans;
        stack <int> s;
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) func(i, adj, vis, s);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        
        return ans;
        
        
        
        
    }
};
