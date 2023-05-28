class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,int val)
    {
        for(int i =0 ;i<9;i++)
        {
            //row check
            if(board[row][i]-'0' == val) return false;
            
            //col check
            if(board[i][col]-'0' == val) return false;
            
            //3*3 check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]-'0' == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int row = 0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col] == '.')
                {
                    for(int val = 1;val<=9;val++)
                    {
                        if(isSafe(row,col,board,val))
                        {
                            char ch = static_cast<char>(val + '0');
                            board[row][col] = ch;
                            if(solve(board))
                                return true;
                            else
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};