class Solution {
public:
    string reverseWords(string s) {
       
        int n=s.length();
        string res="";
        for(int i=0; i<n;)
        {
            if(s[i]==32)
                i++;
            string temp="";
            while(i<n && s[i]!=32)
            {
                temp+=s[i];
                i++;
            }
            if(res!="")
                res=temp+" "+res;
            else
                res=temp;
            while(s[i]==32)
                i++;
        }
        return res;
    }
};
