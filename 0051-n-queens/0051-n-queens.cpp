class Solution {
public:
    void addsolution(vector<vector<char>> &board,vector<vector<string>> &ans)
    {
        vector<string> temp;
        int n = board.size();
        for(int i = 0;i<n;i++)
        {
            string ans  = "";
            for(int j = 0;j<n;j++)
            {
                ans.push_back(board[i][j]);
            }
            temp.push_back(ans);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row,int col,vector<vector<char>> &board,int n,int rowMask,int diag1Mask,int diag2Mask)
    {
        //check for same row
        if(rowMask & (1 << row)) return false;

        //check for diagnol
        if(diag1Mask & (1 << (row + col))) return false;

        if(diag2Mask & (1 << (row - col + n - 1))) return false;

        return true;
    }

    void solve(int col,vector<vector<string>> &ans,vector<vector<char>> &board,int n,int rowMask,int diag1Mask,int diag2Mask)
    {
        if(col == n)
        {
            addsolution(board,ans);
            return;
        }

        for(int row = 0; row < n;row++)
        {
            if(isSafe(row,col,board,n,rowMask,diag1Mask,diag2Mask))
            {
                board[row][col] = 'Q';
                rowMask |= (1 << row);
                diag1Mask |= (1 << (row + col));
                diag2Mask |= (1 << (row - col + n - 1));
                
                solve(col+1,ans,board,n,rowMask,diag1Mask,diag2Mask);
                
                board[row][col] = '.';
                rowMask &= ~(1 << row);
                diag1Mask &= ~(1 << (row + col));
                diag2Mask &= ~(1 << (row - col + n - 1));
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        
        solve(0,ans,board,n,0,0,0);
        
        return ans;
    }
};