class Solution {
public:
    set<vector<int>> ans;
    void generate(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int j=index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            generate(nums,index+1);
            swap(nums[index],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        generate(nums,0);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};