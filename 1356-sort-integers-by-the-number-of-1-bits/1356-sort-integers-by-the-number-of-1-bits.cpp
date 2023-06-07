class Solution {
public:
    static bool compare(const int&a,const int&b)
    {
        int bit1 = __builtin_popcount(a);
        int bit2 = __builtin_popcount(b);
        
        if(bit1 == bit2)
            return a < b;
        
        return bit1 < bit2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};