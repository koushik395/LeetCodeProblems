class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums,int index,int target,vector<int> &subsets)
    {
        if(target == 0)
        {
            ans.push_back(subsets);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            subsets.push_back(nums[i]);
            generate(nums,i+1,target-nums[i],subsets);
            subsets.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subsets;
        generate(candidates,0,target,subsets);
        return ans;
    }
};