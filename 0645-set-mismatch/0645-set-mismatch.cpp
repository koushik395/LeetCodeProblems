class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actualSum = n*(n+1)/2;
        int currentSum = accumulate(nums.begin(),nums.end(),0);
        
        unordered_set<int> temp(nums.begin(),nums.end());
        int setSum = 0;
        for(auto& it:temp) setSum += it;
        
        return {currentSum - setSum , actualSum - setSum};
    }
};