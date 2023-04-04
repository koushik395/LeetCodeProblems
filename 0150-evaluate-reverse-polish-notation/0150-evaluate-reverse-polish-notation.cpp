class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> scores;
        for(auto i: tokens)
        {
            if(i=="+")
            {
                int x = scores.back();
                scores.pop_back();
                int y = scores.back();
                scores.pop_back();
                scores.push_back(x+y);
            }

            else if(i == "-")
            {
                int x = scores.back();
                scores.pop_back();
                int y = scores.back();
                scores.pop_back();
                scores.push_back((y-x));
            }
            else if(i=="*")
            {
                int x = scores.back();
                scores.pop_back();
                int y = scores.back();
                scores.pop_back();
                scores.push_back(x*y);
            }
            else if(i=="/")
            {
                int x = scores.back();
                scores.pop_back();
                int y = scores.back();
                scores.pop_back();
                scores.push_back(y/x);
            }
            else
                scores.push_back(stoi(i));
        }
        return scores.back();
    }
};