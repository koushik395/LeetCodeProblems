class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int threshold)
    {
        int sum = 0;
        for(auto& it: nums)
        {
            sum += ceil(it*1.0/mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end()),ans = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(isPossible(mid,nums,threshold))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};