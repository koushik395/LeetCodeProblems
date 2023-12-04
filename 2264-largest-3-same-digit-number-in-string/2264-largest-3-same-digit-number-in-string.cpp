class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = 0;
        for(int i = 2;i < num.size();i++)
        {
            if(num[i] == num[i-1] && num[i] == num[i-2])
            {
                ch = max(ch,num[i]);
            }
        }
        return ch == 0 ? "" : string(3,ch);
    }
};