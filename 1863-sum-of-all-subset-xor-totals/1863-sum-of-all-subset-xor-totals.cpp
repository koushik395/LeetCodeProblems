class Solution {
public:
    vector<int> allsubsets;
    void generate(vector<int>& subsets,int i,vector<int> nums)
    {
        if(i == nums.size())
        {
            if(!subsets.empty())
            {
                int sum = 0;
                for(int i: subsets)
                {
                    sum = sum ^ i;
                }
                allsubsets.push_back(sum);
            }
            return;
        }

        generate(subsets,i+1,nums);

        subsets.push_back(nums[i]);
        generate(subsets,i+1,nums);
        subsets.pop_back();
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector<int> empty;
        generate(empty,0,nums);
        int sum = 0;
        for(auto subset:allsubsets){
            sum = sum + subset;
        }
        return sum;
    }
};