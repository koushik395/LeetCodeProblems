class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] & 1) 
            {
                j = i;
                break;
            }   
        }
        if(j!=-1)
        for(int i = j+1 ; i < n;i++)
        {
            if((nums[i] & 1) == 0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};