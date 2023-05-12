class Solution {
public:
     //recursion
    
//     int getPoints(vector<vector<int>>& q,int i,int n)
//     {
//         if(i == n-1) return q[i][0];
        
//         if(i >= n) return 0;
        
//         int take = q[i][0] + getPoints(q,i + q[i][1] + 1,n);
//         int nottake = 0 + getPoints(q,i+1,n);
        
//         return max(take,nottake);
//     }
    
      // Memoization
    
//     long long dp[100001] = {};
//     long long getPoints(int i, vector<vector<int>>& q, int n){
        
//         if(i == n-1) return q[i][0];
//         if(i >= n) return 0;
        
//         if(dp[i] != 0) return dp[i];
        
//         long long take = q[i][0] + getPoints(i + q[i][1] + 1, q, n);
//         long long nottake = 0 + getPoints(i + 1, q, n);
        
//         return dp[i] = max(take, nottake);    
//     }
    
    
    long long mostPoints(vector<vector<int>>& q) {
        long long dp[200001] = {};
        for (int i = q.size() - 1; i >= 0; --i)
            dp[i] = max(q[i][0] + dp[q[i][1] + i + 1], dp[i + 1]);
        return dp[0];
        }
};