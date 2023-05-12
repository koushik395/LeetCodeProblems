class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charCounts(26, 0);
        queue<int> nonRepeatingChars; 

        for (int i = 0;i < s.length();i++) {
            char c = s[i];
            charCounts[c-'a']++;

            if (charCounts[c-'a'] == 1) { 
                nonRepeatingChars.push(i); 
            }


            while (!nonRepeatingChars.empty() && charCounts[s[nonRepeatingChars.front()]-'a'] > 1) {
                nonRepeatingChars.pop();
            }
        }
        if(nonRepeatingChars.empty()) return -1;
        return nonRepeatingChars.front();
    }
};