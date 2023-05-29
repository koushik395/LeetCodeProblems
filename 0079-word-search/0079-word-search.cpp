class Solution {
public:
    bool isPerimeter(int i,int j,int rows,int cols)
    {
        return (i>=0 && i < rows && j >=0 && j < cols);
    }

    bool isPossible(vector<vector<char>>& grid,int i,int j,int rows,int cols,string word)
    {
        if(word.length() == 0) return true;

        if(!isPerimeter(i,j,rows,cols)) return false;
        
        bool left = 0,right = 0,up = 0,down = 0;

        if(grid[i][j] == word[0])
        {
            char temp = word[0]; 
            grid[i][j] = ' ';
            word = word.substr(1);
            left = isPossible(grid,i,j-1,rows,cols,word);
            right = isPossible(grid,i,j+1,rows,cols,word);
            up = isPossible(grid,i-1,j,rows,cols,word);
            down = isPossible(grid,i+1,j,rows,cols,word);
            grid[i][j] = temp;
        }
        return left || right || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0;i< rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(isPossible(board,i,j,rows,cols,word))
                        return true;
                }
            }
        }
        return false;
    }
};