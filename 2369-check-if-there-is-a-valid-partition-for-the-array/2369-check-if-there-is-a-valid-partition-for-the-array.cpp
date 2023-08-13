class Solution {
public:
    bool isEqual(vector<int>& nums,int i,int j)
    {
        for(int x = i;x <= j-1;x++)
        {
            if(nums[x] != nums[x+1]) return false;
        }
        return true;
    }
    
    bool isConti(vector<int>& nums,int i,int j)
    {
        if(j-i+1 != 3) return false;
        for(int x = i+1;x <= j;x++)
        {
            if(nums[x] - nums[x-1] != 1) return false;
        }
        return true;
    }
    
    bool solve(vector<int>& nums,int ind,int n,vector<int> &dp)
    {
        if(ind == n) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind+1;i <= min(n-1,ind+2);i++)
        {
            if((isEqual(nums,ind,i) || isConti(nums,ind,i)) && solve(nums,i+1,n,dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,n,dp);
    }
};