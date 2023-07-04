class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        int cnt = 0;
        for(auto& ch:chars)
        {
            mp[ch]++;
        }
        
        for(auto& word: words)
        {
            unordered_map<char,int> curr;
            bool dont = true;
            for(auto& ch:word)
            {
                curr[ch]++;
            }
            
            for(auto& it:curr)
            {
                if(mp[it.first] < it.second) 
                {
                    dont = false;
                    break;
                }
            }
            if(dont) cnt += word.size();
        }
        
        return cnt;
    }
};