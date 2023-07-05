class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, lastZeroIdx = -1, ans = 0;
        while(j < n)
        {
            if(nums[j] == 0)
            {
                i = lastZeroIdx+1;
                lastZeroIdx = j;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};