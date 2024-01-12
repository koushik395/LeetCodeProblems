class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        int a = 0,b = 0,i = 0,j = s.size()-1;
        while(i < j){
            a += (st.find(s[i++])) != st.end() ? 1 : 0;
            b += (st.find(s[j--])) != st.end() ? 1 : 0;
        }
        return a == b;
    }
};