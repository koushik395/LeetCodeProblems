class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int prevZero = 0, currNum = 0, currZero = -1, ans = 0;
        while(currNum < n)
        {
            if(nums[currNum] == 0)
            {
                prevZero = currZero+1;
                currZero = currNum;
            }
            ans = max(ans, currNum-prevZero);
            currNum++;
        }
        return ans;
    }
};