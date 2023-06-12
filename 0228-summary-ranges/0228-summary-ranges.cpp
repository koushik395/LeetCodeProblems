class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0;i < nums.size();i++)
        {
            int start = nums[i],end;
            string res;
            while(i+1 < nums.size() && nums[i]+1 == nums[i+1])
            { 
                i++;
            }
            end = nums[i];
            if(end != start)
                res += to_string(start)+ "->" + to_string(end);
            else
                res += to_string(start);
            ans.push_back(res);
        }
        return ans;
    }
};