class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        vector<pair<int,int>> newarr(n);
        
        for(int i = 0;i < n;i++)
                newarr[i] = make_pair(efficiency[i],speed[i]);
        
        sort(newarr.rbegin(),newarr.rend());
        long long sum = 0,ans = 0;
        
        for(auto& [mul,score]: newarr)
        {
            minheap.push(score);
            sum += score;
            if (minheap.size() > k) {
                sum -= minheap.top();
                minheap.pop();
            }
            ans = max(ans, sum * mul);
        }
        
        return ans%mod;
    }
};