class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int l1 = s.length(), l2 = goal.length();
        if(l1 != l2) return false;
        if(s == goal && unordered_set<char>(s.begin(),s.end()).size() < l1) return true;
        vector<int> diff;
        for(int i = 0;i < l1;i++)
        {
            if(s[i] != goal[i]) diff.push_back(i);
        }
        
        return diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};