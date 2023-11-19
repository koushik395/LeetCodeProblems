class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(rbegin(nums),rend(nums));
        int n = nums.size(),res = 0;
        for(int i = 1;i < n;i++){
            if(nums[i] != nums[i-1])
            {
                res += i;
            }
        }
        return res;
    }
};