class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        while(n--)
        {
            int ans = (digits[n] +carry)%10;
            carry = (digits[n] +carry)/10;
            cout << ans  << " "<< carry << endl;
            digits[n] = ans;
        }
        if(carry)
            digits.insert(digits.begin(),carry);
        return digits;
    }
};