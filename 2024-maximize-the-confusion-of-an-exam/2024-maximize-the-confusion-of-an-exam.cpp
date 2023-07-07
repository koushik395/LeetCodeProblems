class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size() ,left = 0,ans = 0,cnt = 0;
        // conversion of F -> T
        for(int i = 0;i < n;i++)
        {
            if(answerKey[i] == 'F') cnt++;
            
            while(cnt > k)
            {
                if(answerKey[left] == 'F') cnt--;
                left++;
            }
            ans = max(i-left +1,ans);
        }
        
        cnt = 0,left = 0;
        // conversion of T -> F
        for(int i = 0;i < n;i++)
        {
            if(answerKey[i] == 'T') cnt++;
            
            while(cnt > k)
            {
                if(answerKey[left] == 'T') cnt--;
                left++;
            }
            ans = max(i-left +1,ans);
        }
        
        return ans;
    }
};