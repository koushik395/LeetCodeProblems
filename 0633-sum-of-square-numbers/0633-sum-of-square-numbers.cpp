class Solution {
public:
    bool judgeSquareSum(int c) {
        long int a=0;
        long int b=sqrt(c);
        while(a<=b)
        {
            if(a*a+b*b==c)
                return true;
            else if(a*a+b*b>c)
                b--;
            else
                a++;
        }
        return 0;
    }
};