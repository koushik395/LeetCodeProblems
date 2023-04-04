class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> ans;
        int count = 1;
        for(auto i:s)
        {
            if(ans.find(i)!=ans.end())
            {
                count++;
                ans.clear();
            }
            ans[i]++;
        }
        return count;
    }
};