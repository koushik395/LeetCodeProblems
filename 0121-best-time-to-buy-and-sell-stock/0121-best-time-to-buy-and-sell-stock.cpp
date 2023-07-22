class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = INT_MIN;
        for(int i = 1;i < prices.size();i++)
        {
            int val = prices[i] > mini ? prices[i] - mini : INT_MIN;
            ans = max(ans,val);
            mini = min(mini,prices[i]);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};