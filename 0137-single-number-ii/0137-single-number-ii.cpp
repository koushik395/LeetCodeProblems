class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0},ans=0;
        for(auto num:nums)
        {
            for(int i=0;i<32;i++)
            {
                bits[i] += ((num >> i) & 1); //count the number of 1 bits for every number at the corresponding position.
            }
        }
        
        for(int i=0;i<32;i++)
        {
            ans |= ((bits[i]%3) << i); // do %3 because for the elements that appear three times the result at that bit will be 0. The duplicate element appears only once and hence doing %3 gives the corresponding bit value at that position.
        }
        return ans;
    }
};