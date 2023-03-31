class Solution {
public:
    string intToRoman(int num) {
        map<int,string> romans;
        romans[1000] = "M";
        romans[900] = "CM";
        romans[500] = "D";
        romans[400] = "CD";
        romans[100] = "C";
        romans[90] = "XC";
        romans[50] = "L";
        romans[40] = "XL";
        romans[10] = "X";
        romans[9] = "IX";
        romans[5] = "V";
        romans[4] = "IV";
        romans[1] = "I";
        
        auto it = romans.rbegin();
        string str="";
        
       while(num)
       {
           if(num >= it->first)
           {
               str += it->second;
               num -= it->first;
           }
           else
               it++;
       }
        return str;
    }
};