class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int longest = 1;
        unordered_map<int, int> length;

        for (auto ele:arr) {
            longest = max(longest,length[ele] = 1 + length[ele-difference]);
        }
        return longest;
    }
};