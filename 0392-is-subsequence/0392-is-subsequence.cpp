class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        for(i = 0,j = 0;i < t.length();i++)
        {
            if(t[i] == s[j]) j++;
        }
        return j == s.length();
    }
};