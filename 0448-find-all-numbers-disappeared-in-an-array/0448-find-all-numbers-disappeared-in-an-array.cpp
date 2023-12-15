class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> numbers(nums.begin(),nums.end());
        for(int i = 1;i <= nums.size();i++)
        {
            if(numbers.find(i) == numbers.end()) ans.push_back(i);
        }
        return ans;
    }
};