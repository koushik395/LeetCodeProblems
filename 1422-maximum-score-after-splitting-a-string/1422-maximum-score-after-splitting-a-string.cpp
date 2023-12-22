class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, maxi = INT_MIN;
        
        for(int i=0;i<s.size();i++) {
            if(s[i] == '0') zeros++; else ones++;
            if(i != s.length()-1) maxi = max(zeros - ones, maxi);
        }
        return maxi + ones;
    }
};