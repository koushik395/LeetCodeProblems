class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> mp; 
        int maxi= 0;
        char letter;
        for(auto& ch:s) 
        {
            mp[ch]++;
            if(mp[ch] > maxi)
            {
                maxi = mp[ch];
                letter = ch;
            }
        }
        if(maxi > ceil((n*1.0)/2)) return "";
        
        string res(n,' ');
        int idx = 0;
        while(mp[letter] > 0)
        {
            res[idx] = letter;
            idx += 2;
            mp[letter]--;
        }
        for(auto& it:mp)
        {
            while(mp[it.first] > 0)
            {
                if(idx >= n) idx = 1;
                res[idx] = it.first;
                idx += 2;
                mp[it.first]--;
            }
        }
        return res;
    }
};