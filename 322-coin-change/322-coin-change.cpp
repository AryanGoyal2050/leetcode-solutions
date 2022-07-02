class Solution {
public:
    
    int dp[10005];
    
    int func(vector<int>& coins, int a)
    {
        //return the min number of coins required
        //to add up to amount = a
        
        if(a == 0) return 0;
        if(dp[a] != -1) return dp[a];
        
        long long ans = INT_MAX;
        long long z = 0;
        long long one = 1;
        for(int i=0; i<coins.size(); i++)
        {
            if(coins[i] <= a)
            {
                ans = min(ans + z, one + func(coins, a-coins[i]));
            }
        }
        return dp[a] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = func(coins, amount);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};