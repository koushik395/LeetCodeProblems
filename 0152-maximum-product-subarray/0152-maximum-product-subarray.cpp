class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1,maxi = INT_MIN;
        for(int i = 0; i< n;i++)
        {
            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            maxi = max({maxi,pre,suff});
            if(suff == 0) suff = 1;
            if(pre == 0) pre = 1;
        }
        return maxi;
    }
};