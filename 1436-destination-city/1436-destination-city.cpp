class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> mp;
        for(auto& it:paths)
        {
            mp.insert(it[0]);
        }
        
        for(auto& it:paths)
        {
            if(mp.find(it[1]) == mp.end()) 
                return it[1];
        }
        return "";
    }
};