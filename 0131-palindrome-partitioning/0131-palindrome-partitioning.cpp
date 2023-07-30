class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int i,int j,string &str)
    {
        while(i < j)
        {
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,int n,vector<string>& output, vector<vector<string>>& ans,string& s)
    {
        if(idx == n)
        {
            ans.push_back(output);
            return;
        }
        for(int i=idx; i<n; i++)
        {
            if(isPalindrome(idx, i,s))
            {
                output.push_back(s.substr(idx, i-idx+1));
                solve(i+1, n, output, ans, s);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> output;
        solve(0, n, output, ans, s);
        return ans;
    }
};