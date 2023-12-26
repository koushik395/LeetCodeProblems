class Solution {
public:
    #define MOD 1000000007;
    int dp[31][1001] = {};
    int numRollsToTarget(int d, int f, int target,int res = 0) {
        if(d == 0 || target <= 0) return d == target;
        if(dp[d][target]) return dp[d][target] - 1;
        for(int i = 1; i <= f;i++)
        {
            res = (res + numRollsToTarget(d-1,f,target - i)) % MOD;   
        }
        dp[d][target] = res + 1;
        return res;
    }
};