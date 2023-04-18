class Solution {
public:
    bool isPowerOfThree(int n) {
        /*For any N <= M that is a power of 3, M divides N.
          For any N <= M that is not a power 3, M does not divide N
          M = 3^20(as it is the highest num in int range).*/
        
        return (n>0 && 3486784401%n==0);
    }
};