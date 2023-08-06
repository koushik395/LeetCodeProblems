class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;
    ll solve(int n, int goal, int k, vector<vector<int>>& dp) {
        if (n == 0 && goal == 0) return 1;
        if (n == 0 || goal == 0) return 0;
        
        if (dp[n][goal] != -1) return dp[n][goal];
        
        ll pick = solve(n - 1, goal - 1, k, dp) * n;
        //take a new song and select from remaining n-1 songs.
        ll notpick = solve(n, goal - 1, k, dp) * max(n - k, 0); 
        // take an already played song but need to wait upto k songs being played.
        
        return dp[n][goal] = (pick + notpick) % MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        return solve(n, goal, k, dp);
    }
};