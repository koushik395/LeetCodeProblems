class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int,int>> visited;
        int x = 0,y = 0;
        visited.push_back({x,y});
        
        for(auto& it:path)
        {
            if(it == 'N')x--;
            else if(it == 'S') x++;
            else if(it == 'E') y++;
            else y--;
            visited.push_back({x,y});
        }
        set<pair<int,int>> ans(begin(visited),end(visited));
        if(ans.size() != visited.size()) return true;
        return false;
    }
};