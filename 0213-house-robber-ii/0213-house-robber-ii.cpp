class Solution {
public:
    int robber(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0],prev2 = 0;
        for(int i = 1;i < n;i++)
        {
            int take = nums[i] + prev2;
            int nottake = prev1;
            int curr = max(take,nottake);
            prev2 = prev1, prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1(nums.begin(),nums.end());
        vector<int> temp2(nums.begin(),nums.end());
        
        temp1.pop_back();
        temp2.erase(temp2.begin());
        
        return max(robber(temp1),robber(temp2));
    }
};