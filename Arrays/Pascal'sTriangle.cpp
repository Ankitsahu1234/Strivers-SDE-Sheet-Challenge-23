class Solution {
public:

    // To calculate nCr
    int nCr(int n, int r)
    {
        if(r==0 || r==n)    
            return 1;
        if(r>n-r)
            r=n-r;
        int ans=1;
        for(int i=0; i<r; i++)
        {
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        // Start from here
      
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++)
        {
            vector<int> temp;
            for(int j=0; j<=i; j++)
            {
                int x=nCr(i, j);
                temp.push_back(x);
            }
            res.push_back(temp);
        }
        return res;
    }
};

