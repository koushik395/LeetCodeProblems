class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i = 0;i < groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        
        for(auto& it:mp)
        {
            int size = it.first;
            vector<int> pep = it.second;
            int batches = pep.size()/size;
            
            while(batches--)
            {
                vector<int> temp;
                int j = 0;
                for(int i = 0;i < size;i++)
                {
                    temp.push_back(pep[j++]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};