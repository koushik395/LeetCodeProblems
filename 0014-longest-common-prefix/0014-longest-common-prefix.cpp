class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int c = 0;
        string first = strs[0];
        string last = strs[strs.size()-1];
        
        while(c < first.length())
        {
            if(first[c] == last[c]) c++;
            else break;
        }
        
        return c == 0? "":first.substr(0,c);
    }
};