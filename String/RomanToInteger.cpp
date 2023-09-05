class Solution {
public:
    int romanToInt(string s) {
      
        unordered_map<char,int> T={{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int sum=0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(i-1 != -1)
            {
                if(T[s[i]]>T[s[i-1]])
                {
                    sum+=T[s[i]] - T[s[i-1]];
                    i--;
                }
                else
                {
                    sum+=T[s[i]];
                } 
            }
            else
            {
                sum+=T[s[i]];
            } 
        }
        return sum;
    }
};
