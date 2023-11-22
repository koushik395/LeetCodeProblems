class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> ans;
        for(int s  = 0;s <= (row + col - 2);s++)
        {
            for(int x = 0; x <= s;x++)
            {
                int i = x;
                int j = s - i;
                if(!(s & 1)) swap(i,j);

                if(i >= row || j >= col) continue;
                
                ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
};