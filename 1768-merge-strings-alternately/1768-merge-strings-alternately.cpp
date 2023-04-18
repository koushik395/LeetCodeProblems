class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i=0,j=0;
        string s = "";
        while(i<n && j<m)
        {
            s.push_back(word1[i]);
            s.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<n)
        {
            s.push_back(word1[i]);
            i++;
        }
        while(j<m)
        {
            s.push_back(word2[j]);
            j++;
        }
        return s;
    }
};