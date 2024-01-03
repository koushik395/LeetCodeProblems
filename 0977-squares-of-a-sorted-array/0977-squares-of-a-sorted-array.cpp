class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0,j = nums.size()-1,k = nums.size()-1;
        vector<int> ans(nums.size(),0);
        while(i <= j)
        {
            if(pow(nums[i],2) > pow(nums[j],2))
            {
                ans[k--] = pow(nums[i],2);
                i++;
            }
            else{
                ans[k--] = pow(nums[j],2);
                j--;
            }
        }
        return ans;
    }
};