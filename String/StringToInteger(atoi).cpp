class Solution {
public:
    int myAtoi(string s) {
        
        // Method 2:
        
        int n=s.length();
        int i=0;
        double num=0;
        while(i<n && s[i]==' ')
        {
            i++;
        }
        bool negative=(s[i]=='-') ? true : false;
        if(i<n && (s[i]=='-' || s[i]=='+'))
            i++;
        while(i<n)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                num=num*10+(s[i]-48);
            }
            else
                break;   
            i++;
        }
        num=(negative==true) ? -num : num;
        num=(num>INT_MAX) ? INT_MAX : num;
        num=(num<INT_MIN) ? INT_MIN : num;
        return (int)num;

    }
};
