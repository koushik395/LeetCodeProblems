class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation = 0;
        for(int i = 1;i < nums.size();i++)
        {
            int num = nums[i];
            nums[i] = max(nums[i-1] + 1,nums[i]);
            operation += nums[i]-num;
        }
        return operation;
    }
};