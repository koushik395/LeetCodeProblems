class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& word: words)
        {
            if(equal(begin(word),end(word),rbegin(word)))
            {
                return word;
            }
        }
        return "";
    }
};