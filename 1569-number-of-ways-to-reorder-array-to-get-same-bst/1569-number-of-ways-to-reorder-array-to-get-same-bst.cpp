class Solution {
    private:
    long long dfs(vector<vector<long long>> &table,vector<int> &nums,int &mod)
    {
        int n = nums.size();
        if(n <= 2)
        {
            return 1;
        }
        
        vector<int> left,right;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long left_val = dfs(table,left,mod);
        long long right_val = dfs(table,right,mod);
        
        int left_len = left.size(),right_len = right.size();
        return ((table[n-1][left_len] * left_val)%mod * right_val)%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> table(n+1,vector<long long>(n+1,1));
        
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j < i;j++)
            {
                table[i][j] = (table[i-1][j-1] + table[i-1][j])%mod;
                //nCr = n-1Cr-1 + n-1Cr;
            }
        }
        
        long long ans = dfs(table,nums, mod);
        return (ans % mod - 1)%mod; //subtract 1 cause already one permutation is given
    }
};