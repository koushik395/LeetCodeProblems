class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> numbers(begin(nums), end(nums));
        vector<int> ans(size(nums) - size(numbers));
        for(int i = 1, j = 0; i <= size(nums); i++)  
            if(!numbers.count(i)) ans[j++] = i;
        return ans;
    }
};