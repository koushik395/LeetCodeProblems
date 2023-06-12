class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3)
        {
            return -1;
        }
        int maxi = max({nums[0],nums[1],nums[2]});
        int mini = min({nums[0],nums[1],nums[2]});
        
        for(int i = 0; i< 3;i++)
        {
            if(mini < nums[i] && nums[i] < maxi)
            {
                return nums[i];
            }
        }
        return -1;
    }
};