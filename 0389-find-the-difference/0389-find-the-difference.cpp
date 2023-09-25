class Solution {
public:
    char findTheDifference(string s, string t) {
        s += t;
        int c = 0;
        for(auto& it:s)
        {
            c ^= it;
        }
        return c;
    }
};