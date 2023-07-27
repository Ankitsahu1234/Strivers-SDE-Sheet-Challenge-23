class Solution {
public:
    int solveRec(int m, int n, vector<vector<int>> &memo, int i, int j)
    {
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(memo[i][j]!=-1)
            return memo[i][j];
        int paths=solveRec(m, n, memo, i+1, j)+solveRec(m, n, memo, i, j+1);
        memo[i][j]=paths;
        return memo[i][j];
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveRec(m, n, memo, 0, 0);
    }
};

// // Method 3:
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
        
//         // Method 3: Optimal
//         int N=(n+m-2);
//         int r=m-1;      // Or r=n-1
//         double res=1;
//         for(int i=1; i<=r; i++)
//         {
//             res=res*(N-r+i)/i;
//         }
//         return (int)res;
//     }
// };
