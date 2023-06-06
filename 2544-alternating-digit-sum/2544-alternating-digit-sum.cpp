class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while(n > 0){
            sign *= -1;
            res += n%10 * sign;
            n/=10;
        }
        return res*sign;
    }
};