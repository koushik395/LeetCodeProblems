class Solution {
public:
    int countNegatives(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowindex = 0;
        int colindex = col-1;
        
        int ans = 0;
        while(rowindex < row && colindex >=0)
        {
            int element = matrix[rowindex][colindex];
            if(element < 0)
            {   
                ans += (row-rowindex);
                colindex--;
            }
            else
            {
                rowindex++;
            }
            
        }
        return ans;
    }
};