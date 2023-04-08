class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romans={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        auto it = s.rbegin();
        int ans = romans[*(it)];
        it++;
        while(it!= s.rend())
        {
            if(romans[*(it)] < romans[*(it-1)])
                ans -= romans[*(it)];
            else
                ans += romans[*(it)]; 
            it++;
        }
        return ans;
    }
};