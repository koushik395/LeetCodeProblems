class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            long long lcmNum = nums[i];
            if(lcmNum == k)
                count++;
            for(int j=i+1;j<n;j++)
            {
                lcmNum = lcm(lcmNum,nums[j]);
                if(lcmNum > k) break;
                if(lcmNum == k)
                    count++;
            }
        }
        return count;
    }
};