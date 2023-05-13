class Solution {
public:
    const int mod = 1e9 + 7;
    int score(int target, vector<int>& dp, int one, int zero)
    {
        // if target is 0 that means this target can be made so return 1
        if (target == 0)
            return 1;
        // target < 0 cannot be made 
        if (target < 0)
            return 0;
        // if already computed eturn the value
        if (dp[target] != -1)
            return dp[target];
        long long sum;
        // target - a is adding 'a' 0's to the string
        // target - b is adding 'b' 1's to string 
        sum =  score(target - one, dp, one, zero) + score(target - zero, dp,one, zero);
        return dp[target] = (sum % (mod));
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);

        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans = ((ans % mod) + ( score(i, dp, one, zero) % mod )) % mod;
        }
        return ans;
        
        //BOTTOM UP DP
//         vector<int> dp(high + 1);
//         dp[0] = 1;
//         int res = 0, mod = 1e9 + 7;
//         for (int i = 1; i <= high; ++i) {
//             // Add Zero to the number of times it can be added to string of length (i-zero)
//             if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            
//             /* Add Ones to the number of times it can be added to string of length (i-ones)
//             Also add the result to number of times of zeros
//             */
//             if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            
//             // if i is in between low and high add 
//             if (i >= low) res = (res + dp[i]) % mod;
//         }
//         return res;

    }
};