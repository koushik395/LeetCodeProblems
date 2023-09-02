class Solution {
public:
    int n;
    int find(string &s,unordered_map<string,int>& mp,vector<int> &dp,int idx)
    {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
            
        int mini = n;
        for(int i = idx;i < n;i++)
        {
            string word = s.substr(idx,i - idx + 1);
            int extra = mp.count(word) ? 0: word.size();
            int next = find(s,mp,dp,i+1);
            
            mini = min(mini,extra + next);
        }
        return dp[idx] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        unordered_map<string,int> mp;
        vector<int> dp(n+1,0);
        for(auto& dic:dictionary) mp[dic]++;
        
        for(int i = n-1;i >= 0;i--)
        {
            int mini = n;
            for(int j = i;j < n;j++)
            {
                string word = s.substr(i,j - i + 1);
                int extra = mp.count(word) ? 0: word.size();
                int next = dp[j+1];

                mini = min(mini,extra + next);
            }
            dp[i] = mini;
        }
        
        return dp[0];
    }
};