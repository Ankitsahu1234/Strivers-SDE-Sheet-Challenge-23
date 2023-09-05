class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        // Method 2:

        for(int i=0; i<A.size(); i++)
        {
            int j;
            for(j=0; j<B.size(); )
            {
                if(A[(i+j)%A.size()]==B[j])
                    j++;
                else
                    break;
            }
            if(j==B.size())
                return ((i+B.size()-1)/A.size())+1;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
        
//         set<int> myset;
//         for(char ch: a)
//             myset.insert(ch);
//         for(char ch: b)
//         {
//             if(myset.find(ch)==myset.end())
//                 return -1;
//         }
//         string temp=a;
//         int res=1;
//         while(1)
//         {
//             if(temp.find(b)!=string::npos)
//                 return res;
//             else if(temp.length()>12*b.length())
//                 return -1;
//             else
//             {
//                 temp+=a;
//                 res++;
//             }
//         }
//         return res;
//     }
// };
