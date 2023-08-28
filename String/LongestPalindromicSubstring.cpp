class Solution{   
public:

    string helper(string &s, int left, int right)
    {
        int n=s.length();
        while(left>=0 && right<n && s[left]==s[right])
        {
            left--;
            right++;
        }
        int len=(right-1)-(left+1)+1;
        string res=s.substr(left+1, len);
        return res;
    }
    
    string longestPalindrome(string S){
        // code here 
        
        // Method 2: "Expanding From the Center" Approach
        
        int n=S.length();
        int len=0;
        string ans;
        for(int i=0; i<n; i++)
        {
            string temp=helper(S, i, i);
            if(len<temp.size())
            {
                len=temp.size();
                ans=temp;
            }
            temp=helper(S, i, i+1);
            if(len<temp.size())
            {
                len=temp.size();
                ans=temp;
            }
        }
        return ans;
    }
};
