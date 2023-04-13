class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> res;
        int i = 0,j=0;
        while(i < pushed.size() && j < popped.size())
        {
            int val = pushed[i];
            if(val == popped[j])
            {
                res.push(val);
                while(!res.empty() && res.top() == popped[j])
                {
                    res.pop();
                    j++;
                }
            }
            else
                res.push(val);
            i++;
        }
        return res.size()==0;
    }
};