class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int startrow = 0;
        int startcol = 0;
        int endrow = row-1;
        int endcol = col-1;

        int count = 0;
        while(count < total){
            for(int index = startcol;count<total && index <= endcol;index++)
            {
                matrix[startrow][index] = count + 1;
                count++;
            }
            startrow++;
            for(int index = startrow;count<total && index <= endrow; index++)
            {
                matrix[index][endcol] = count + 1;
                count++;
            }
            endcol--;
            for(int index = endcol;count<total && index >= startcol; index--)
            {
                matrix[endrow][index] = count + 1;
                count++;
            }
            endrow--;
            for(int index = endrow;count<total && index >= startrow; index--)
            {
                matrix[index][startcol] = count + 1;
                count++;
            }
            startcol++;
        }
        return matrix;
        
    }
};