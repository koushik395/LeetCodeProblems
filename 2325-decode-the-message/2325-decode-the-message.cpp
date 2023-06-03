class Solution {
public:
    string decodeMessage(string key, string message) {
        stringstream ss(key);
        unordered_map<char,char> mp;
        string ans,word;
        int cnt = 0;
        while(ss >> word)
        {
            for(int i = 0;i < word.length();i++)
            {
                char ch = word[i];
                if(mp.find(ch) == mp.end())
                {
                    mp[ch] = 'a' + cnt;
                    cnt++;   
                }
            }
        }
        
        for(auto& ch:message)
        {
            if(ch == ' ')ans.push_back(ch);
            else ans.push_back(mp[ch]);
        }
        return ans;
    }
};