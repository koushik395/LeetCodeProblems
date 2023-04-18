class Solution {
public:
    bool isPowerOfThree(int n) {
        /*For any N <= M that is a power of 3, N divides M.
          For any N <= M that is not a power 3, N does not divide M
          M = 3^20(as it is the highest num in int range).*/
        
        return (n>0 && 3486784401%n==0);
    }
};