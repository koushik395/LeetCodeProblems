class Solution {
public:
    vector<vector<int>> ans;
    void generate(int start,int n,int k,vector<int>& comb)
    {
        if(k == 0)
        {
            ans.push_back(comb);
            return;
        }

        for(int idx = start;idx <= n;idx++)
        {
            comb.push_back(idx);
            generate(idx+1,n,k-1,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        generate(1,n,k,comb);
        return ans;
    }
};