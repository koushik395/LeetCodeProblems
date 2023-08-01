class Solution {
public:
    string reverseWords(string s) {
        string finalword,word;
        stringstream ss(s);
        
        while(ss >> word)
        {
            finalword = word +" "+ finalword;
        }
        finalword.pop_back();
        return finalword;
    }
};