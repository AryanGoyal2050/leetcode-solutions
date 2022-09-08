class Solution {

private:
    
    int check(int days, vector<int>& bloomDay, int m, int k)
    {
        int ans = 0;
        int n = bloomDay.size();
        int curr = 0;
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= days) curr++;
            else curr = 0;
            if(curr >= k)
            {
                curr = 0;
                ans++;
            }
        }
        
        return (ans >= m);
        
        
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        //make a set of bloomDays
        //binary search on set
        //each search takes O(n) time
        
        int n = bloomDay.size();
        
        set <int> s;
        for(int i=0; i<n; i++)
        {
            s.insert(bloomDay[i]);
        }
        
        if(m*k > n) return -1;
        
        vector <int> day(s.begin(), s.end());
        
        int p1 = 0;
        int p2 = day.size()-1;
        
        int ans = day[day.size()-1];
        
        while(p2>=p1)
        {
            int mid = (p1+p2)/2;
            int x = check(day[mid], bloomDay, m, k);
            if(x)
            {
                ans = min(ans, day[mid]);
                p2 = mid-1;
            }
            else
            {
                p1 = mid+1;
            }
        }
                         
        return ans;
    }
};