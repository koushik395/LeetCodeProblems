class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int sum1 = 0,sum2 = 0,j=0;
        for(int i = 0;i < rows;i++)
        {
            sum1 += mat[i][i];
        }
        for(int i = rows-1; i >=0 ;i--)
        {
            sum2 += mat[j++][i];
        }
        if(rows & 1) return ((sum1 + sum2)-mat[rows/2][rows/2]);
        else return (sum1+sum2);
    }
};