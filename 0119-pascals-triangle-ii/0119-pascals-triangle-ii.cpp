class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        int n = rowIndex + 1;
        vector<int> ans(1,1);
        long long res = 1;
        for(int i=1;i<n;i++)
        {
            res = res *1LL* (n - i);
            res = res / i;
            ans.push_back(res);
        }
        return ans;
    }
};