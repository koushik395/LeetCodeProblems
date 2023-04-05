class Solution {
public:
    bool solve(int max, vector<int> &a) {
        long ex = 0;
        for (int i : a) {
            if (i > max) {
                long c = (i - max);
                if (c > ex) return false;
                ex -= c;
            } else {
                ex += (max - i);
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int s = 0, e = (int) 1e9, ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (solve(mid, nums)) {
                e = mid - 1;
                ans = mid;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};