class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums,int n,int target,vector<int> subsets)
    {
        if(target == 0)
        {
            ans.push_back(subsets);
            return;
        }
        if(n == 0)
            return;
        
        if(nums[n-1] > target)
            generate(nums,n-1,target,subsets);
        else {
            subsets.push_back(nums[n-1]);
            generate(nums,n,(target-nums[n-1]),subsets);
            subsets.pop_back();
            generate(nums,n-1,target,subsets);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subsets;
        int n = candidates.size();
        generate(candidates,n,target,subsets);
        return ans;
    }

};