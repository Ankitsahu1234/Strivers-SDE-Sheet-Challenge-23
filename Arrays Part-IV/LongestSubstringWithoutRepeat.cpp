class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        if(n==0 || n==1)
            return n;
        int maxLen=1;
        for(int i=0; i<n; i++)
        {
            string str="";
            str+=s[i];
            unordered_set<char> myset;
            myset.insert(s[i]);
            for(int j=i+1; j<n; j++)
            {
                if(myset.find(s[j])!=myset.end())
                    break;
                str=str+s[j];
                if(str.length() > maxLen)
                    maxLen=str.length();
                myset.insert(s[j]);
            }
        }
        return maxLen;
    }
};
