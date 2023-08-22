class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber)
        {
            columnNumber -= 1;
            ans.push_back(columnNumber % 26 + 65);
            columnNumber /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};