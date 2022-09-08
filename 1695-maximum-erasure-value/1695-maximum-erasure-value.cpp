class Solution {
public:
    
    
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int arr[10005]; //stores the last occurance of an element
        memset(arr, -1, sizeof(arr));
        
        int n = nums.size();
        
        vector <int> presum(n, 0);    //sum of all elements index <= i
        presum[0] = nums[0];
        
        for(int i=1; i<n; i++)
        {
            presum[i] = nums[i] + presum[i-1];
        }
        
        int p1 = 0;
        int p2 = 0;
        arr[nums[0]] = 0;
        //beginning and ending indices of the current subarray of unique
        
        int ans = nums[0];
        int curr = nums[0];
        
        for(int i=1; i<n; i++)
        {
            int l = arr[nums[i]];
            arr[nums[i]] = i;
            if(l >= p1 and l <= p2)
            {
                //reset the subarray
                //with just one element that is nums[i]
                p1 = l+1;
                p2 = i;
                curr = presum[i]-presum[l];
                
            }
            else
            {
                curr += nums[i];
                p2 = i;
            }
                
            ans = max(ans, curr);
        }
        
        return ans;
        
        
    }
};
