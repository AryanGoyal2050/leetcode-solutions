class Solution {
private:
    static bool comp(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string (b);
        
        string x = s1+s2;
        string y = s2+s1;
        
        return (x>y);
    }
    
    string remove_zeroes(string s)
    {
        string ans;
        int p = 0;
        
        while(s[p] == '0')
        {
            p++;
            if(p >= s.length()) break;
        }
        
        while(p < s.length())
        {
            ans += s[p];
            p++;
        }
        
        if(ans.length() == 0) return "0";
        
        return ans;
    }
    
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), comp);
        
        string s;
        for(int i=0; i<n; i++)
        {
            s += to_string(nums[i]);
        }
        
        cout<<remove_zeroes("0000");
        
        return remove_zeroes(s);
        
    }
};
