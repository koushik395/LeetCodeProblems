class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> adjSum;
        for(int i = 0;i < n-1;i++)
        {
            adjSum.push_back(weights[i] + weights[i+1]);
        }
        
        long long minSum = 0,maxSum = 0;
        sort(adjSum.begin(),adjSum.end());
        for(int i = 0;i < k-1;i++)
        {
            minSum += adjSum[i];
            maxSum += adjSum[n-2-i];
        }
        return maxSum - minSum;
        
    }
};