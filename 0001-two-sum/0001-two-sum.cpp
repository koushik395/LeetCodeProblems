class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> index;
        vector<int> res;
        for(int i =0;i<nums.size();i++)
        {
            int num = nums[i];
            int extra = target - num;
            if(index.find(extra)!=index.end())
            {
                res.push_back(i);
                res.push_back(index[extra]);
                break;
            }
            index[num] = i;
        }
        return res;
    }
};