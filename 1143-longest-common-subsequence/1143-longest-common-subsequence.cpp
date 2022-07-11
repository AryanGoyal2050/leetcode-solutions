class Solution {
public:
    
    int dp[1005][1005];
    
    int func(int p1, int p2, string &a, string &b)
    {
        //returns the of longest commom subsequence in
        //  string a -> index <= p1
        //  string b -> index <= p2
        
        if(p1 < 0 || p2 < 0) return 0;
        if(dp[p1][p2] != -1) return dp[p1][p2];
        
        if(a[p1] == b[p2])
        {
            //cout<<"++ for "<<p1<<" "<<p2<<endl;
            return 1+func(p1-1, p2-1, a, b);
        }
        
        int ans = INT_MIN;
        ans = max(ans, func(p1-1, p2, a, b));
        ans = max(ans, func(p1, p2-1, a, b));
        
        return dp[p1][p2] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        memset(dp, -1, sizeof(dp));
        
        return func(text1.length()-1, text2.length()-1, text1, text2);
    }
};
