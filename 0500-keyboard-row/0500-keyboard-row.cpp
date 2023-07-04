class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mp;
        vector<string> ans;
        
        vector<string> keys = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        int i = 1;
        for(auto& word:keys)
        {
            for(auto& ch:word)
            {
                mp[ch] = i;
            }
            i++;
        }
        
        for(auto& word:words)
        {
            int first = -1;
            bool include = true;
            for(auto ch:word)
            {
                ch = tolower(ch);
                if(first == -1)
                {
                    first = mp[ch];
                }
                else if(mp[ch] != first)
                {
                    include = false;
                    break;
                }
            }
            
            if(include) ans.push_back(word);
        }
        return ans;
    }
};