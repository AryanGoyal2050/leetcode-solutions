//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector <string> ans;
    
    map <pair <int, int>, int> vis;
    
    void func(int r, int c, vector <vector <int>> &m, int n, string s)
    {
        //currently at (r, c)
        //s is the path followed from (0, 0) to (r, c)
        //cout<<" "<<s<<endl;
        vis[{r, c}] ++;
        
        if(r == n-1 and c == n-1)
        {
            ans.push_back(s);
            return ;
        }
        
        //(r+1, c)
        if(r+1 < n and r+1 >= 0 and !vis[{r+1, c}]) 
        {
            if(m[r+1][c]) func(r+1, c, m, n, s+'D');
            vis[{r+1, c}] = 0;
        }
        
        //(r-1, c)
        if(r-1 < n and r-1 >= 0 and !vis[{r-1, c}])
        {
            if(m[r-1][c]) func(r-1, c, m, n, s+'U');
            vis[{r-1, c}] = 0;
        }
        
        //(r, c+1)
        if(c+1 < n and c+1 >= 0 and !vis[{r, c+1}])
        {
            if(m[r][c+1]) func(r, c+1, m, n, s+'R');
            vis[{r, c+1}] = 0;
        }
        
        //(r, c-1)
        if(c-1 < n and c-1 >= 0 and !vis[{r, c-1}])
        {
            if(m[r][c-1]) func(r, c-1, m, n, s+'L');
            vis[{r, c-1}] = 0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0] == 0 or m[n-1][n-1] == 0) return ans;
        
        func(0, 0, m, n, "");
        
        return ans;
    }
};
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends