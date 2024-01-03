class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0,res = 0;
        for(auto& it:bank)
        {
            int cur = count(begin(it),end(it),'1');
            if(cur){
                res += cur * prev;
                prev = cur;
            }
        }
        return res;
    }
};