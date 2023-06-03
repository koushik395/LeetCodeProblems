class Solution {
public:
    string helper(string &s,int &index)
    {
        string res;
        while(index < s.length() && s[index]!=']')
        {
            if(isdigit(s[index]))
            {
                int num = 0;
                while(s[index]!='[')
                {
                    num = num * 10 + s[index]-'0';
                    index++;
                }
                
                index++;//skip open brace
                
                string ans = helper(s,index); //extract the word in the braces
                
                for(int x =0; x < num;x++)
                {
                    res += ans;
                }
                
                index++;
            }
            else
            {
                res += s[index];
                index++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return helper(s,index);
    }
};