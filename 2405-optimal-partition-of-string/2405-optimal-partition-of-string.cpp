class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> ans;
        int count = 1;
        for(auto i:s)
        {
            if(ans.find(i)!=ans.end())
            {
                count++;
                ans.clear();
            }
            ans.insert(i);
        }
        return count;
    }
};