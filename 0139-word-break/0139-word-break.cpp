
class Solution {
private:
    int n;
    unordered_map<string, bool> hashMap;
    int memo[300];
    bool containsWord(string& s, int idx, int k)
    {
        string word = s.substr(idx, k-idx+1);
        return hashMap.count(word);
    }
    bool solve(string& s, int idx)
    {
        if(idx >= n)
        {
            return true;
        }
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        bool check = false;
        for(int k=idx; k<n; k++)
        {
            if(containsWord(s, idx, k))
            {
                check = check || (solve(s, k+1));
            }
        }
        return memo[idx] = check;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto& word: wordDict)
        {
            hashMap[word] = true;
        }
        memset(memo, -1, sizeof(memo));
        return solve(s, 0);
        
    }
};