class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<32> ans(n);
        bitset<32> one(1);
        int i=0,evenCount=0,Oddcount = 0;
        while(ans.count())
        {
            int val = (ans&one).count();
            if(i&1)
                Oddcount += val;
            else
                evenCount+= val;
            ans >>= 1;
            i++;
        }
        cout << evenCount << Oddcount<<endl;
        return {evenCount,Oddcount};
    }
};