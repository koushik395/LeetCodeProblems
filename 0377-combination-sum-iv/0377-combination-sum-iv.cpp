class Solution {
public:
//     int find(vector<int>& nums, int target)
//     {
//         if(target == 0) return 1;
        
//         int cnt = 0;
//         for(auto& num:nums)
//         {
//             if(target < num) break;
//             cnt += find(nums,target-num);
//         }
//         return cnt;
//     }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        
        for(int i = 1;i <= target;i++)
        {
            for(auto& num:nums)
            {
                if(i < num) break;
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};