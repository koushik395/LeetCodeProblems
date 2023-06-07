class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        
        while(c || a || b)
        {
            bool cbit = c&1;
            bool bbit = b&1;
            bool abit = a&1;
            
            if(cbit)
            {
                if(!(abit | bbit))
                {
                    cnt++;
                }
            }
            else
            {
                if(abit)
                {
                    cnt++;
                }
                if(bbit)
                {
                    cnt++;
                }
            }
            a >>=1;
            b >>=1;
            c >>=1;
        }
        return cnt;
    }
};