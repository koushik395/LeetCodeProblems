class Solution {
public:
    void compare(string &s,string &t,int index1,int index2)
    {
        if(index1 == 0 && s[index1] == '#')
        {
            s.erase(index1,1);
            compare(s,t,index1,index2);
        }
        if(index2 == 0 && t[index2] == '#')
        {
            t.erase(index2,1);
            compare(s,t,index1,index2);
        }
        if(index1>=s.length() && index2 >= t.length())
            return;
        if(index1 < s.size() && s[index1]=='#')
        {
            if(index1>0)
                s.erase(index1-1,2);
            compare(s,t,index1-1,index2);
        }
        if(index2 < t.size() && t[index2]=='#')
        {
            if(index2 > 0 )
                t.erase(index2-1,2);
            compare(s,t,index1,index2-1);
        }
        cout << s << " "<< t << endl;
        compare(s,t,index1+1,index2+1);

    }
    bool backspaceCompare(string s, string t) {
        compare(s,t,0,0);
        cout << s << " "<< t << endl;
        if(s == t)
            return 1;
        return 0;
    }
};