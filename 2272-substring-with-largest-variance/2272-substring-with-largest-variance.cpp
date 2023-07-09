class Solution {
public:
    int largestVariance(string s) {
        vector<int> freq(26,0);
        int ans = 0;
        for(auto& it:s)
        {
            freq[it-'a']++;
        }
        
        for(char x = 'a' ;x <= 'z';x++)
        {
            for(char y = 'a';y <= 'z';y++)
            {
                if(x == y || !freq[x-'a'] || !freq[y-'a']) continue;
                
                for(int rev = 1;rev <= 2;rev++)
                {
                    int ch1 = 0,ch2 = 0;
                    for(auto& it:s)
                    {
                        ch1 += it == x;
                        ch2 += it == y;
                        if(ch1 < ch2) 
                        {
                            ch1 = 0;
                            ch2 = 0;
                        }
                        if(ch1 > 0 && ch2 > 0)
                        {
                            ans = max(ans,ch1-ch2);
                        }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};