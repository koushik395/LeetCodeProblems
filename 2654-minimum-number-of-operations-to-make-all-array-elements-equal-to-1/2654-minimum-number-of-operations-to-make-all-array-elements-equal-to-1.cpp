class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(),onesCount = 0,gcd = 0;
        for(int i =0;i < n;i++)
        {
            if(nums[i] == 1) onesCount++;
            gcd = __gcd(gcd,nums[i]);
        }
        if(gcd != 1) return -1;
        
        if(onesCount) return n - onesCount;
        
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            int res = nums[i];
            for(int j = i; j < n; j++) {
                res = __gcd(nums[j], res);
                if(res == 1) mini = min(mini, j - i);
            }
        }
        
        return n + mini -1;
    }
};