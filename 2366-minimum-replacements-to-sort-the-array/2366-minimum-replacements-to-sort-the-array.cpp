class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operations = 0; 
        int prev_end = nums[nums.size() - 1];

        for(int i = nums.size() - 2; i >=0; i--) {
            // if greater then prev_end of last
            if(nums[i] > prev_end) {
                int steps = (nums[i]-1)/ prev_end;
                operations += steps;
                prev_end = nums[i] / (steps + 1);
            } else {
                prev_end = nums[i];
            }
        }

        return operations;
    }
};