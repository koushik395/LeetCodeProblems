class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n,0);
        pre[0] = nums[0];
        
        for(int i = 1;i < n;i++)
        {
            pre[i] = nums[i] + pre[i-1];
        }
        
        vector<int> ans(n,0);
        
        for(int i = 0;i < n;i++)
        {
            int preVal = i == 0 ? 0 : pre[i-1];
            ans[i] = (nums[i] * i - preVal) + ((pre[n-1]-pre[i]) - nums[i]*(n-i-1));
            
        }
        return ans;
    }
};


// For nums[i], the answer is (nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ... + (nums[n-1] - nums[i]).