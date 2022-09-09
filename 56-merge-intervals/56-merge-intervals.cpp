class Solution {
private:
    
    bool comp(vector <int> a, vector <int> b)
    {
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0])
        {
            return (a[1] > b[1]);
        }
        return false;
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector <vector <int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0] <= ans[ans.size()-1][1])
            {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
        
    }
};
