class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        // remove valid strings
        for(auto &i:s)
        {
            if(i=='(')
              st.push(i);
            else
            {
               if(!st.empty() && st.top()=='(')
                  st.pop();
               else
                  st.push(i);
            }
        }
        return st.size();
    }
};