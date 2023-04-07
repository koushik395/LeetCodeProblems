class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())
            return 0;
        bitset<50001> flag;
        bitset<50001> str(1);
        int i = 0,j = 0,ans = 1;
         while((i <=j) && (j < s.size())){
            int val = s[j];
            int x = (flag & (str<<val)).count();
            if(x) {
                int dup = s[i];
                flag.reset(dup);
                i++;
            }else{
                flag = flag | (str<<val);
                int size = flag.count();
                ans = max(ans,size);
                str.reset();
                str.set(0);
                j++;
            }
        }
        return ans;
    }
};