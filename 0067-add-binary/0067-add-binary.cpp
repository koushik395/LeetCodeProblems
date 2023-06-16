class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0,i = a.length()-1,j = b.length()-1;
        string res = "";
        while(i >=0 || j>=0)
        {
            int sum  =carry;
            if(i >=0) sum += a[i--]-'0';
            if(j>=0) sum+= b[j--]-'0';
            carry = sum > 1?1:0;
            res += to_string(sum % 2);
        }
        if(carry) res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};