class Solution {
public:
    vector<vector<int>> direc = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    unordered_map<string,double> mp;
    
    double find(int &n,int row,int col,int moves)
    {
        if(row < 0 || col < 0 || row >= n || col >= n) return 0;
        
        if(moves == 0) return 1;
        
        string key = to_string(row) + "-" + to_string(col) + "-" + to_string(moves);
        if(mp.find(key) != mp.end()) return mp[key];
        
        double probability = 0;
        for(int i = 0;i < 8;i++)
        {
            probability += find(n,row + direc[i][0],col + direc[i][1],moves-1)/8.0;
        }
        
        return mp[key] = probability;
    }
    double knightProbability(int n, int k, int row, int column) {
        return find(n,row,column,k);
    }
};