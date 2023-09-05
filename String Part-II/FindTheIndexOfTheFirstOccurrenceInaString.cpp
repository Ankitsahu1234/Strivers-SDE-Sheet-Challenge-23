class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.length();
        int m=needle.length();
        for(int i=0; i<n; i++)
        {
            if(haystack[i]==needle[0])
            {
                int t=i+1;
                int j=1;
                while(t<n && j<m)
                {
                    if(haystack[t]==needle[j])
                        j++;
                    else
                        break;
                    t++;
                }
                if(j==m)
                    return i;
            }
        }
        return -1;
    }
};
