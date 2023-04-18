class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string res = "";
        while(i<word1.length() && j<word2.length())
            res = res + word1[i++] + word2[j++];
        return res + word1.substr(i) + word2.substr(j);
    }
};