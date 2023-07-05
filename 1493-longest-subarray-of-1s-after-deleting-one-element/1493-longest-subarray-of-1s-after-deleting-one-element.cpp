class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = -1;
        vector<int> cnt(2,0);
        
        int i = 0,j = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0)
            {
                if(cnt[0] >= 1)
                {
                    maxi = max(maxi,cnt[1]);
                    while(i <= j && nums[i] != 0)
                    {
                        cnt[1]--;
                        i++;
                    }
                    i++;
                }
                else
                {
                    cnt[0]++;
                }
            }
            else
            {
                cnt[1]++;
            }
            j++;
        }
        
        maxi = max(maxi,cnt[1]);
        return cnt[0] > 0 ? maxi:nums.size()-1;
    }
};