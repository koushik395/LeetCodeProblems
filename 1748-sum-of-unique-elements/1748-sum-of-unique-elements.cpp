class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_set<int> mp,mp1;
        int total = 0;
        for(auto& num:nums)
        {
            if(mp.find(num) != mp.end())
            {
                total -= num;
                mp.erase(num);
                mp1.insert(num);
            }
            else if(mp1.find(num) == mp1.end())
            {
                mp.insert(num);
                total += num;
            }
        }
        return total;
    }
};