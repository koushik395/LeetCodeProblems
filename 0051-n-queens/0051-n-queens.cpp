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

    bool isSafe(int row,int col,vector<vector<char>> &board,int n)
    {
        int x = row;
        int y = col;

        //check for same row
        while(y >=0)
        {
            if(board[x][y]=='Q') return false;
            y--;
        }

        x = row;
        y = col;
        //check for diagnol
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q') return false;
            y--;
            x--;
        }

        x = row;
        y = col;
        //check for diagnol
        while(x < n && y>=0)
        {
            if(board[x][y]=='Q') return false;
            x++;
            y--;
        }
        return true;
    }

    void solve(int col,vector<vector<string>> &ans,vector<vector<char>> &board,int n)
    {
        if(col == n)
        {
            addsolution(board,ans);
            return;
        }

        for(int row = 0; row < n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,ans,board,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        
        solve(0,ans,board,n);
        
        return ans;
    }
};