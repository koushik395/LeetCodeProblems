class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = __builtin_popcount(c ^= a|b) + __builtin_popcount(a&b&c);
        return ans;
    }
};