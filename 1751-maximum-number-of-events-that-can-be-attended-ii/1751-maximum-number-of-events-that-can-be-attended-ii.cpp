class Solution {
public:
    // recursion
//     int f(int pos,int k,vector<vector<int>>& events,vector<vector<int>> &dp)
//     {
//         int n = events.size(),i;
//         if(k == 0 || pos >= n) return 0;
//         if(dp[pos][k] != -1) return dp[pos][k];
        
//         for(i = pos + 1;i < n;i++)
//         {
//             if(events[i][0] > events[pos][1]) //find next day
//             {
//                 break;
//             }
//         }
        
//         int take = events[pos][2] + f(i,k-1,events,dp); 
//         int notake = f(pos+1,k,events,dp);
        
//         return dp[pos][k] = max(take,notake);
    // }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int currK = 1; currK <= k; currK++) {
                vector<int> temp = {events[pos][1],INT_MAX,INT_MAX};
                int nextDay = upper_bound(events.begin()+pos+1,events.end(),temp) - events.begin();
                
                int take = (nextDay < n) ? events[pos][2] + dp[nextDay][currK - 1] : events[pos][2];
                int notake = dp[pos + 1][currK];

                dp[pos][currK] = max(take, notake);
            }
        }

        return dp[0][k];
    }
};