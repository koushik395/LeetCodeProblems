class Solution {
public:
    vector<long long> ans;
    int cnt = 0;
    void dfs(long long finalSum,long long num)
    {
        long long newSum = finalSum - num;
        
        if(newSum >= 0)
        {
            ans.push_back(num);
            dfs(newSum,num+2);
            if(cnt == 0)
            {
                ans.pop_back();
                ans.push_back(finalSum);
                cnt++;
            }
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 == 1) return {};
        dfs(finalSum,2);
        return ans;
    }
};