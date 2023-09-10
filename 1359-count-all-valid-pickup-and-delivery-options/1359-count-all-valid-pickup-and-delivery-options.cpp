class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n) {
        int res = 1;
        for(int i = 1;i <= n;i++) res = (res *1LL* i) % mod;
        for(int i = 1;i < 2 * n;i+=2) res = (res *1LL* i) % mod;
        return res;
    }
};