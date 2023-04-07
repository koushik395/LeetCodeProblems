class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0},ans=0;
        for(auto num:nums)
        {
            for(int i=0;i<32;i++)
            {
                bits[i] += ((num >> i) & 1);
            }
        }
        
        for(int i=0;i<32;i++)
        {
            ans |= ((bits[i]%3) << i);
        }
        return ans;
    }
};