class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        for(int i=0; i<n; i++)
        {
            if(strs[i].size()==0)
                return "";
        }
        string res="";
        for(int i=0; i<strs[0].length(); i++)
        {
            char ch=strs[0][i];
            int count=1;
            for(int j=1; j<n; j++)
            {
                if(i<strs[j].length() && strs[j][i]==ch)
                {
                    count++;
                }
                else
                    break;
            }
            if(count==n)
                res+=ch;
            else
                break;
        }
        return res;
    }
};
