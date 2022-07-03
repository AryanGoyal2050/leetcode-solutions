class Solution {
public:
    
    int dp[10005][305];
    //dp[i][j] stores the number of ways
    //to make total amount of i
    //only using elements >= coins[j]
    
    int func(int ind, int a, vector<int>& coins)
    {
        //return the number of combinations
        //that add up to amount = a
        //elements only >= coins[ind]
        
        if(a == 0) return 1;
        if(a < 0) return 0;
        if(ind < 0) return 0;
        
        if(dp[a][ind] != -1) return dp[a][ind];
        
        int ans = 0;
        
        for(int i=0; i <= a; i += coins[ind])
        {
            ans += func(ind-1, a-i, coins);
        }
        
        return dp[a][ind] = ans;
    }
    
    int change(int amount, vector<int>& coins) {
        
        memset(dp, -1, sizeof(dp));
        
        return func(coins.size()-1, amount, coins);
    }
};