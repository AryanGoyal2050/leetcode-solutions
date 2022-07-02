class Solution {
public:
    
    int dp[3000];
    
    int func(vector <int> &nums, int k)
    {
        //func return the length of the longest subarray that ends on index k
        if(k == 0) return 1;
        if(dp[k] != -1) return dp[k];
        
        int m = 1;
        for(int i=k-1; i>=0; i--)
        {
            if(nums[i] < nums[k])
            {
                m = max(m, 1+func(nums, i));
            }
        }
        
        return dp[k] = m;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            ans = max(ans, func(nums, i));
        }
        
        return ans;
        
    }
};