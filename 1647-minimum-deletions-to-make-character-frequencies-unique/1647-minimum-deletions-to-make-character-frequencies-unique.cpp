class Solution {
public:
    int minDeletions(string s) {
        int arr[26] = {0};
        for(auto& it:s) arr[it-'a']++;
        
        unordered_set<int> st;
        int del = 0;
        
        for(int i = 0;i < 26;i++)
        {
            while(arr[i] > 0 && !st.insert(arr[i]).second)
            {
                arr[i]--;
                del++;
            }
        }
        return del;
    }
};