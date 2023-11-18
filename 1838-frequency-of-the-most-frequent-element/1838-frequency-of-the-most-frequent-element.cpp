class Solution {
public:
    /**
     Number of operations needed for all elements in the window [startIndex, endIndex] to hit A[endIndex]
     Example:
     Consider arr with [1, 2, 3, 4] with startIndex = 0; endIndex = 3: i.e If 1, 2, 3 wants to become 4.
     Number of operations needed
     = (4-1)+(4-2)+(4-3)+(4-4) = 6.
     =  4 + 4 + 4 + 4 - (1 + 2 + 3+ 4)
     = 4 * 4 - (1 + 2 + 3 + 4)
     = (number of elements) * ElementToReach - sum of elements in the window
     */
    long long NumOfOperations(int left,int right,long long currSum,vector<int>& nums)
    {
        long numOfElements = right - left + 1;
        int elementToReach = nums[right];
        
        return ((long long) numOfElements *1L* elementToReach) - currSum;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int res = 1,left = 0;
        long long sumOfElements = 0;
        sort(nums.begin(),nums.end());
        
        for(int right = 0;right < nums.size();right++){
            sumOfElements += nums[right];
            
            while(NumOfOperations(left,right,sumOfElements,nums) > k){
                sumOfElements -= nums[left];
                left++;
            }
            res = max(res,right-left + 1);
        }
        return res;
    }
};