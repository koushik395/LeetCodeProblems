class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count = 0;
                for (int k = 0; k < dirs.size(); k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x > m - 1 || y < 0 || y > n - 1) continue;
                    count += (board[x][y] & 1);
                }
                if ((count == 2 && board[i][j]) || count == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
};