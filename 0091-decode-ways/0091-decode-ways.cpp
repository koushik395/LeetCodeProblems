class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        
        for (int i = 2; i <= n; i++) {
            int first = stoi(s.substr(i - 1, i - (i-1)));
            int second = stoi(s.substr(i - 2, i - (i-2)));
            if (first >= 1 && first <= 9) {
               dp[i] += dp[i-1];  
            }
            if (second >= 10 && second <= 26) {
                dp[i] += dp[i-2];
            }
            if(dp[i] == 0) return 0;
        }
        return dp[n];
    }
};