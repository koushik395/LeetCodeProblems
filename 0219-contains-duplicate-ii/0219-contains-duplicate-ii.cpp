class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> index;
        for(int i =0;i<nums.size();i++)
        {
            int num = nums[i];
            if(index.find(num)!=index.end())
            {
                if(abs(index[num] - i) <= k)
                    return true;
            }
            index[num] = i;
        }
        return false;
    }
};