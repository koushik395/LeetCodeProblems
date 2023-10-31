class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if(pref.size() == 1) return {pref[0]};
        
        vector<int> ans(1,pref[0]);
        
        for(int i = 1;i < pref.size();i++){
            ans.push_back(pref[i] ^ pref[i-1]);
        }
        return ans;
    }
};