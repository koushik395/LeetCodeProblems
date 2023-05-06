class Solution {
public:
    int pow_mod(int base, int exp, int mod) {
        int res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res *1LL* base) % mod;
            }
            base = (base *1LL* base) % mod;
            exp /= 2;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                cnt = (cnt + pow_mod(2, right - left, mod)) % mod;
                left++;
            }
        }
        return cnt;
    }

};