class Solution {
public:
    bool winnerOfGame(string s) {
        if(s.size() <= 2) return false;
        
        int a = 0,b = 0;
        for(int i = 1;i < s.size()-1;i++)
        {
            if(s[i-1] == s[i] && s[i] == s[i+1])
            {
                if(s[i] == 'A') a++;
                else b++;
            }
        }
        return a > b;
    }
};