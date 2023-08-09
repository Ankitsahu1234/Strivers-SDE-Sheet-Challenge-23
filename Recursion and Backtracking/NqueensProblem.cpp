class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
            return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(vector<string> &board, int col, int n, vector<vector<string>> &res)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(isSafe(board, row, col, n))
            {
                board[row][col]='Q';
                solve(board, col+1, n, res);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board(n);
        string str(n, '.');
        for(int i=0; i<n; i++)
        {
            board[i]=str;
        }
        solve(board, 0, n, res);
        return res;
    }
};
