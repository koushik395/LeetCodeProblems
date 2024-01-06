class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff; //2's complement
        vector<int> rets(2, 0);
        for (int num : nums)
            rets[!(num & diff)] ^= num;
        return rets;
    }
};