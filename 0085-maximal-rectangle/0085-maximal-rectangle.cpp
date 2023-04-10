class Solution {
public:
    void next(int* heights,int n,vector<int> &nextSmaller)
    {
        stack<int> s;
        s.push(-1);
        n--;
        for(int i=n;i>=0;i--)
        {
            while(s.top()!=-1 && heights[s.top()]>= heights[i])
                s.pop();
            nextSmaller[i] = s.top();
            s.push(i);
        }
    }
    void prev(int* heights,int n,vector<int> &prevSmaller)
    {
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && heights[s.top()]>= heights[i])
                s.pop();
            prevSmaller[i] = s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(int* heights,int n) {
        vector<int> nextSmaller(n);
        next(heights,n,nextSmaller);
            
        vector<int> prevSmaller(n);
        prev(heights,n,prevSmaller);
        
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int *arr = new int[col];
        for(int j=0;j<col;j++)
            arr[j] = matrix[0][j] - '0';
        //compute area for 1st row
        int area = largestRectangleArea(arr,col);
        
        //compute area for next rows
        for(int i=1;i<row;i++)
        {
            int *arr1 = new int[col];
            for(int j=0;j<col;j++)
            {
                arr1[j] = matrix[i][j]-'0';
                if(matrix[i][j]!='0')
                {
                    arr1[j] = arr1[j] + arr[j];
                }
                else
                {
                   arr1[j] = 0;
                }
            }
            //entire row updated
            area = max(area,largestRectangleArea(arr1,col));
            arr  = arr1;
        }
        return area;
    }
};