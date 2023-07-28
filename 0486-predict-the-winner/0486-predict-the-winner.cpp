class Solution {
public:
    int f(vector<int>& nums,int start,int end)
    {
        if(start == end) return nums[start];
        
        return max(nums[start] - f(nums,start+1,end),nums[end] - f(nums,start,end-1));
    }
    bool PredictTheWinner(vector<int>& nums) {
        return f(nums,0,nums.size()-1) >= 0;
    }
};