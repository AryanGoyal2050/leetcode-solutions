class Solution {
private:
    
    int func(int i, int j, int n1, int n2, vector<int>& nums1, vector<int>& nums2, vector <vector <int>> & dp)
    {
        //returns the max length 
        //subarray1 ends at i
        //subarray2 ends at j
        
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(nums1[i] == nums2[j]) return dp[i][j] = 1+func(i-1, j-1, n1, n2, nums1, nums2, dp);
        return dp[i][j] = 0;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector <vector <int>> dp(n1, vector <int> (n2, -1));
        //max equal length
        //nums1 ends at i
        //nums2 ends at j
        
        int ans = INT_MIN;
        
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                ans = max(ans, func(i, j, n1, n2, nums1, nums2, dp));
            }
        }
        
        return ans;
        
    }
};
