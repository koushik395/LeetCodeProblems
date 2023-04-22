class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()<=1)
            return nums[0]==1;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ans = __gcd(ans,nums[i]);
            if(ans==1)
                return 1;
        }
        return 0;
    }
};