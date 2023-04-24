class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char> res;
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        pre[0] = suf[n-1] = 1;
        res.insert(s[0]);
        int count = 0;
        for(int i= 1;i<n;i++)
        {
            res.insert(s[i]);
            pre[i] = res.size();
        }
        res.clear();
        res.insert(s[n-1]);
        for(int i= n-2;i>=0;i--)
        {
            res.insert(s[i]);
            suf[i] = res.size();
        }
        for(int i=1;i<n;i++)
            if(pre[i-1] == suf[i])
                count++;
        return count;
    }
};