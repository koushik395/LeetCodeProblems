class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums.size() > 2 ? nums[1]:-1;
    }
};