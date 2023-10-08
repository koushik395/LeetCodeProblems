class Solution {
public:
    int N, M, K;
    const int MOD = 1e9+7;
    int memo[50][102][51];
    int solve(int idx, int maxEle, int cost) {
        if (idx == N) {
            return cost == K;
        }
        if (memo[idx][maxEle][cost] != -1) {
            return memo[idx][maxEle][cost];
        }
        int ways = 0;
        for (int choice = 1; choice <= M; choice++) {
            if (maxEle < choice) {
                ways = (ways + solve(idx+1, choice, cost+1)) % MOD;
            } else {
                ways = (ways + solve(idx+1, maxEle, cost)) % MOD;
            }
        }
        return memo[idx][maxEle][cost] = ways;
    }
    int numOfArrays(int n, int m, int k) {
        N = n, M = m, K = k;
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0);
    }
};