class Solution {
public:
    bool isPowerOfThree(int n) {
        /*For any M <= N that is a power of 3, M divides N.
          For any M <= N that is not a power 3, M does not divide N*/
        return (n>0 && 3486784401%n==0);
    }
};