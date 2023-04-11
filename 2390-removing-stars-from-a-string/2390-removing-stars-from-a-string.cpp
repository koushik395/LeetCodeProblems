class Solution {
public:
    string removeStars(string s) {
        stack<char> letter;
        string ans;
        for(auto &i:s)
        {
            if(i != '*')
                letter.push(i);
            else
            {
                if(letter.size()!=0)
                    letter.pop();
            }
        }
        while(letter.size())
        {
            char a = letter.top();
            letter.pop();
            ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};