class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0],prev2 = 0;
        for(int i = 1;i < n;i++)
        {
            int take = nums[i] + prev2;
            int nottake = prev1;
            int curr = max(take,nottake);
            prev2 = prev1, prev1 = curr;
        }
        return prev1;
    }
};