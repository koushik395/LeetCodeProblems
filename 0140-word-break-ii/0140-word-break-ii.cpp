class Solution {
public:
    int n;
    vector<string> output;
    unordered_map<string,bool> mp;
    
    void solve(string &s,string &st,int idx)
    {
        if(idx >= n)
        {
            st.pop_back();
            output.push_back(st);
            return;
        }
        
        string currWord = "";
        string temp = st;
        for(int i = idx;i < n;i++)
        {
            currWord.push_back(s[i]);
            if(mp.count(currWord))
            {
                st += currWord + " ";
                solve(s,st,i+1);
                st = temp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        string st = "";
        for(auto& word: wordDict)
        {
            mp[word] = true;
        }
        solve(s,st,0);
        return output;
    }
};