class Solution {
public:
    double myPow(double a, int b) {
        double ans = 1;
        int x = b;
        if(b < 0)
            b = abs(b);
        while(b > 0)
        {
            if(b & 1)
            {
                ans = ans * a;
            }
            a = a * a;
            b >>= 1;
        }
        if(x < 0)
            return (1/ans);
        return ans;
    }
};