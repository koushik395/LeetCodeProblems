class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size(),mid;
        while(low < high){
            mid = (low+high)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        // if(high < 0)
        //     return 0;
        return high;
    }
};