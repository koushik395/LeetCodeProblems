class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(32,0);
        int ans = 0;
        
        for(auto& it: s) freq[it-'a']++;
        for(auto& it: t){
            freq[it-'a']--;
            if(freq[it-'a'] < 0) ans++;
        }
        return ans;
    }
};