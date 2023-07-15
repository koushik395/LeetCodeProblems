class Solution {
public:
    int f(int pos,int k,vector<vector<int>>& events,vector<vector<int>> &dp)
    {
        int n = events.size(),i;
        if(k == 0 || pos >= n) return 0;
        if(dp[pos][k] != -1) return dp[pos][k];
        
        for(i = pos + 1;i < n;i++)
        {
            if(events[i][0] > events[pos][1]) //find next day
            {
                break;
            }
        }
        
        int take = events[pos][2] + f(i,k-1,events,dp); 
        int notake = f(pos+1,k,events,dp);
        
        return dp[pos][k] = max(take,notake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        return f(0,k,events,dp);
    }
};