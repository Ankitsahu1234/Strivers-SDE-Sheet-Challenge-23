class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        set<int> myset;
        for(char ch: a)
            myset.insert(ch);
        for(char ch: b)
        {
            if(myset.find(ch)==myset.end())
                return -1;
        }
        string temp=a;
        int res=1;
        while(1)
        {
            if(temp.find(b)!=string::npos)
                return res;
            else if(temp.length()>12*b.length())
                return -1;
            else
            {
                temp+=a;
                res++;
            }
        }
        return res;
    }
};
