class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26,0);
        for(auto& it: word)
        {
            freq[it-'a']++;
        }
        
        for(int i = 0;i < 26;i++)
        {
            vector<int> temp = freq;
            if(temp[i] <= 0) continue;
            temp[i]--;
            
            unordered_set<int> st;
            for(auto& x:temp)
            {
                if(x > 0)
                {
                    st.insert(x);
                }
            }
            
            if(st.size() == 1) return true;
        }
        return false;
    }
};