class Solution {
public:
    vector<vector<int>> ans;
    void generate(int k,int num,int target,vector<int>& subsets)
    {
        if(target == 0 && k == 0)
        {
            ans.push_back(subsets);
            return;
        }
        for(int i = num;i <= 9;i++)
        {
            if(i > target) break;
            subsets.push_back(i);
            generate(k-1,i+1,target-i,subsets);
            subsets.pop_back();
        }      
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k*(k+1)/2 > n) return {};
        
        vector<int> subsets;
        generate(k,1,n,subsets);
        return ans;
    }
};