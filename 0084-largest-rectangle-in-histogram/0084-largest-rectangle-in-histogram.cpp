class Solution {
public:
    void next(vector<int>& heights,vector<int> &nextSmaller)
    {
        stack<int> s;
        s.push(-1);
        int n = heights.size()-1;
        for(int i=n;i>=0;i--)
        {
            while(s.top()!=-1 && heights[s.top()]>= heights[i])
                s.pop();
            nextSmaller[i] = s.top();
            s.push(i);
        }
    }
    void prev(vector<int>& heights,vector<int> &prevSmaller)
    {
        stack<int> s;
        s.push(-1);
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && heights[s.top()]>= heights[i])
                s.pop();
            prevSmaller[i] = s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n);
        next(heights,nextSmaller);
            
        vector<int> prevSmaller(n);
        prev(heights,prevSmaller);
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int l = heights[i];
            if(nextSmaller[i]==-1)
                nextSmaller[i] = n;
            int b = nextSmaller[i] - prevSmaller[i] - 1;
            int newArea = l*b;
            ans = max(ans,newArea);
        }
        return ans;
    }
};