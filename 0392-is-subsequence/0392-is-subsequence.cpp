class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=0,j =0 ;
        for(int i = 0;i < t.length();i++)
            if(t[i] == s[j]) {
                cnt++;
                j++;
            }
        if(cnt == s.length())
            return true;
        return false;
    }
};