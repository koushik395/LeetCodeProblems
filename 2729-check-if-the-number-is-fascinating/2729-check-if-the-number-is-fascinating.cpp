class Solution {
public:
    bool isFascinating(int n) {
        string num1 = to_string(n*2);
        string num2 = to_string(n*3);
        
        string res = to_string(n) + num1 + num2;
        unordered_map<int, int> mp;
        for(auto it: res){
            if(it != '0'){
                mp[it]++;
                if(mp[it] > 1) return false;
            }
        }
        return mp.size() == 9;
    }
};