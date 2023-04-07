class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums, int n, int target, vector<int>& subset) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        if (n == 0 || target < 0) {
            return;
        }
        // Include the current element and recurse with the same index
        subset.push_back(nums[n-1]);
        generate(nums, n, target-nums[n-1], subset);
        subset.pop_back();
        // Exclude the current element and recurse with the previous index
        generate(nums, n-1, target, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subsets;
        int n = candidates.size();
        generate(candidates, n, target, subsets);
        return ans;
    }

};