class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> chars(26,0);
        
        for(auto& c:s)
        {
            int idx = c-'a';
            if(chars[idx]!=0)
                return c;
            else
                chars[idx]++;
        }
        return 0;
    }
};