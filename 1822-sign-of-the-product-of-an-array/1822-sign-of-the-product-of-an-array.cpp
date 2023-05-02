class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCnt = 0,posCnt = 0;
        for(auto & num : nums)
        {
            if(num < 0) negCnt++;
            else if(num > 0) posCnt++;
            else return 0;
        }
        return negCnt & 1 ? -1 : 1;
    }
};