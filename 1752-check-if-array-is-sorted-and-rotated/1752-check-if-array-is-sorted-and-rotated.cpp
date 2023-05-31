class Solution {
public:
    bool check(vector<int>& nums) {
        int i,maxi = 0,mini = 0,rotidx = -1;
        for(i = 1;i < nums.size();i++)
        {
            if(nums[i] < nums[i-1]) {
                rotidx = i;
                maxi = nums[i-1];
                mini = nums[0];
                break;
            }
        }
        if(rotidx != -1)
        {
            for(int x = i; x < nums.size();x++)
            {
                if(nums[x] > maxi || nums[x] > mini || ((rotidx != x) && (nums[x] < nums[x-1])))
                    return false;
            }
        }
        return true;
    }
};