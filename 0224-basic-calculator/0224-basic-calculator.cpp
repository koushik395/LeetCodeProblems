class Solution {
public:
    int calculate(string s) {
        auto it = s.find("(-");
        if(it!=-1)
        {
            s.replace(it,2,"(0-");
        }
        vector<int> signs(2,1);//[1,1]
        int res = 0;
        
        for(int i = 0;i< s.length();i++)
        {
            if(isdigit(s[i]))
            {
                long long num = 0;
                while(i < s.length() && isdigit(s[i]))
                {
                    num = num*10 + s[i]-'0';
                    i++;
                }
                res += num*signs.back();
                signs.pop_back();
                i--;
            }
            else if(s[i]==')') signs.pop_back();
            else if(s[i] != ' ')
            {
                signs.push_back(signs.back()*(s[i]=='-'?-1:1));
            }
        }
        return res;
    }
};