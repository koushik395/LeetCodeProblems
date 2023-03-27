class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int l = 0, r = 0, n = nums.size(), sum = 0, temp = 0;
        while (r < n) {
            if(r > 0 && nums[r] <= nums[r-1])
            {
                temp = max(temp,sum);
                sum = 0;
            }
            sum+=nums[r++];
        }
        return max(temp, sum);
    }
};