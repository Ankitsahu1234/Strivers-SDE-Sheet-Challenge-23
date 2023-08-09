class Solution{
    public:
    void solve(vector<vector<int>> &m, int i, int j, string str, vector<string> &res, int n)
    {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0)
            return;
        if(i==n-1 && j==n-1 && m[i][j]==1)
        {
            res.push_back(str);
            return;
        }
        if(m[i][j]==1)
        {
            m[i][j]=0;
            solve(m, i, j+1, str+'R', res, n);
            solve(m, i+1, j, str+'D', res, n);
            solve(m, i, j-1, str+'L', res, n);
            solve(m, i-1, j, str+'U', res, n);
            m[i][j]=1;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> res;
        solve(m, 0, 0, "", res, n);
        return res;
    }
};
