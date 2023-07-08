class Solution {
public:
    bool isPower(int num)
    {
        while(num > 1)
        {
            if(num%5 != 0)
            {
                return false;
            }
            num /= 5;
        }
        return num == 1;
    }
    int f(string &s,int start,vector<int> &memo)
    {
        if(start >= s.length())
        {
            return 0;
        }
        
        if(memo[start]!=-1) return memo[start];
        
        int result = INT_MAX;
        string substring;
        for(int i = start;i < s.length();i++)
        {
            substring.push_back(s[i]);
            if(substring[0] == '0')
            {
                break;
            }
            
            int num  = stoi(substring,nullptr,2);
            if(isPower(num))
            {
                int remaining = f(s,i+1,memo);
                if(remaining != -1)
                {
                    result = min(result,1+remaining);
                }
            }
        }
        memo[start] = (result == INT_MAX)?-1:result;
        return memo[start];
    }
    int minimumBeautifulSubstrings(string s) {
        vector<int> memo(s.length(),-1);
        return f(s,0,memo);
    }
};