class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            while (j < nums.size() && nums[j] < nums[i] + n)
                res = min(res, n - (++j - i));  
            if(j > n) break;
        }
        return res;
    }
};