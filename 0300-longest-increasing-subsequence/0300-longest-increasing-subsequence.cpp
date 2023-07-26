class Solution {
public:
    // int n = nums.size();
    //     vector<int> dp(n,1);
    //     int maxi = -1;
    //     for(int i = 0;i < n;i++)
    //     {
    //         int currMax = 1;
    //         for(int j = 0;j < i;j++)
    //         {
    //             if(nums[j] < nums[i])
    //             {
    //                 currMax = max(currMax,dp[j]+dp[i]);
    //             }
    //         }
    //         dp[i] = currMax;
    //         maxi = max(maxi,dp[i]);
    //     }
    //     return maxi;
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the first element >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};