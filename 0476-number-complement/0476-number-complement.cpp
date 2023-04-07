class Solution {
public:
    int findComplement(int num) {
        int comp = 1;
        while (comp < num) 
            comp = (comp << 1) | 1;
        return num ^ comp;
    }
};