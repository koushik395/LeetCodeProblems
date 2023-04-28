class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.length();
        while(n > 0 && s[n-1] == ' ') n--;
        while(n > 0 && s[n-1] != ' ') count++,n--;
        return count;
    }
};