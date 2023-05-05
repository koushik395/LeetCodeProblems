class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi = 0,n;
        deque<int> q;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        for(int i=0;i<k;i++)
        {
            if(vowels.find(s[i]) != vowels.end())
                q.push_back(i);
        }
        n = q.size();
        if(q.size()>0)
            maxi = max(maxi,n);
        
        for(int i = k;i<s.length();i++)
        {
            if(!q.empty() && (i-q.front()>=k))
                q.pop_front();
            
            if(vowels.find(s[i]) != vowels.end())
                q.push_back(i);
            
            n = q.size();
            if(q.size()>0)
                maxi = max(maxi,n);
        }
        return maxi;
    }
};