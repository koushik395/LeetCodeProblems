class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 2, n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = nums[j] - nums[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(res, dp[d][j]);
            }
        return res;
    }
};