class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for(auto i:nums)
            numbers.insert(i);
        return nums.size()!=numbers.size();
    }
};