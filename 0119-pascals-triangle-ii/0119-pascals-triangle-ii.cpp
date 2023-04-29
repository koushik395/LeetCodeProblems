class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * 1LL * (n - i);
            res = res /(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        int n = rowIndex + 1;
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            res.push_back(nCr(n-1,i-1));
        }
        return res;
    }
};