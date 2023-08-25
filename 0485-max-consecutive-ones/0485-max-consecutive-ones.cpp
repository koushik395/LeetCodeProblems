class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int one = 0,maxi = 0;
        for(auto& num:nums)
        {
            if(num == 0) one = 0;
            else
            {
                one++;
                maxi = max(maxi,one);
            }
        }
        
        return maxi;
    }
};