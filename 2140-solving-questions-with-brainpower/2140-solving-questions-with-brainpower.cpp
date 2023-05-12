class Solution {
public:
//     recursion
//     int getPoints(vector<vector<int>>& q,int i,int n)
//     {
//         if(i == n-1) return q[i][0];
        
//         if(i >= n) return 0;
        
//         int take = q[i][0] + getPoints(q,i + q[i][1] + 1,n);
//         int nottake = 0 + getPoints(q,i+1,n);
        
//         return max(take,nottake);
//     }
    
    
    long long dp[200001] = {};
    long long getPoints(int i, vector<vector<int>>& q, int n){
        
        if(dp[i] != 0) return dp[i];
        
        if(i == n-1) return q[i][0];
        if(i >= n) return 0;
        
        long long take = q[i][0] + getPoints(i + q[i][1] + 1, q, n);
        long long nottake = 0 + getPoints(i + 1, q, n);
        
        return dp[i] = max(take, nottake);    
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return getPoints(0,questions,n);
    }
};