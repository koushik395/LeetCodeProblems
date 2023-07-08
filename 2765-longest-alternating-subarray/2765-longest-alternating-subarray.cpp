class Solution {
public:
    bool isAlternating(vector<int>& nums, int right, int left) {
        int distance = right - left;
        if (distance % 2 == 1) {
            // Odd distance, check for consecutive increasing elements
            if (nums[right] - nums[left] == 1 && nums[left + 1] - nums[left] == 1)
                return true;
            return false;
        } else {
            // Even distance, check for equal elements
            return nums[right] - nums[left] == 0;
        }
    }

    int alternatingSubarray(vector<int>& nums) {
        int maxLength = 0;
        int left = 0;
        
        for (int right = 1; right < nums.size(); right++) {
            while (!isAlternating(nums, right, left)) {
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        
        return (maxLength <= 1) ? -1 : maxLength;
    }
};