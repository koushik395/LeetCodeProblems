class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size()-1;
        int low=0,high=len,mid;
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]>=nums[0])
            {
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        if((nums[low]<=target)&&(target<=nums[len]))
            high = len;
        else{
            high = low - 1;
            low = 0;
        }
        while(low<=high)
        {
            mid = (low+high)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};