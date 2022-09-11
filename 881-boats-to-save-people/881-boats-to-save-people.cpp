class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int p1 = 0;
        int p2 = n-1;
        
        int ans = 0;
        
        while(p1 <= p2)
        {
            if(p1 == p2)
            {
                ans++;
                break;
            }
            
            if(people[p1]+people[p2] <= limit) p1++;
            p2--;
            ans++;
        }
        
        return ans;
        
    }
};