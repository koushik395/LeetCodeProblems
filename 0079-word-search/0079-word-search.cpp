class Solution {
public:
    bool isPerimeter(int i, int j, int rows, int cols) {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
    }

    bool isPossible(vector<vector<char>>& grid, int i, int j, int rows, int cols, const string& word, int index) {
        if (index == word.length()) {
            return true;
        }

        if (!isPerimeter(i, j, rows, cols) || grid[i][j] != word[index]) {
            return false;
        }

        char temp = grid[i][j];
        grid[i][j] = ' ';

        bool found = isPossible(grid, i, j - 1, rows, cols, word, index + 1) ||
                     isPossible(grid, i, j + 1, rows, cols, word, index + 1) ||
                     isPossible(grid, i - 1, j, rows, cols, word, index + 1) ||
                     isPossible(grid, i + 1, j, rows, cols, word, index + 1);

        grid[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, const string& word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (isPossible(board, i, j, rows, cols, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

};