class Solution {
public:
    void FloodFill(vector<vector<int>>& grid,int i,int j,int rows,int cols,int Scol,int Ecol)
    { 
        if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j]==Scol)
        {
            grid[i][j] = Ecol;
            FloodFill(grid,i-1,j,rows,cols,Scol,Ecol);
            FloodFill(grid,i+1,j,rows,cols,Scol,Ecol);
            FloodFill(grid,i,j+1,rows,cols,Scol,Ecol);
            FloodFill(grid,i,j-1,rows,cols,Scol,Ecol);   
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int startCol = image[sr][sc];
        if(startCol == color)
            return image;
        FloodFill(image,sr,sc,rows,cols,startCol,color);
        return image;
    }
};