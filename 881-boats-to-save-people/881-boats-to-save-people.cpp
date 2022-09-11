class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        
        sort(people.begin(), people.end());
        
        int p1 = 0;
        int p2 = n-1;
        
        int ans = 0;
        int curr = 0;
        
        while(p1 <= p2)
        {
            if(p1 == p2)
            {
                ans++;
                break;
            }
            
            curr = 0;
            curr += people[p2];
            p2--;
            if(curr+people[p1] <= limit)
            {
                curr += people[p1];
                p1++;
            }
            ans++;
            curr = 0;
        }
        
        return ans;
        
    }
};