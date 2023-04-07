class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())
            return 0;
        unordered_set<char> str;
        int i = 0,j=0,ans = 1;
        while((i <= j) && (j<s.size()))
        {
            if(str.find(s[j])!= str.end())
            {
                str.erase(s[i]);
                i++;
            }else{
                str.insert(s[j]);
                int size = str.size();
                cout <<s[j]<<" "<< size << endl;
                ans = max(ans,size);
                j++;
            }
        }
        return ans;
    }
};