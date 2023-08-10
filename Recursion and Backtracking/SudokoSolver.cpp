class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>> &board)
    {
        for(int i=0; i<9; i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
        }
        int rr=3*(row/3);
        int cc=3*(col/3);
        for(int i=rr; i<rr+3; i++)
        {
            for(int j=cc; j<cc+3; j++)
            {
                if(board[i][j]==c)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, vector<pair<int,int>> &pos, int i)
    {
        if(i==pos.size())
            return true;
        int r=pos[i].first;
        int c=pos[i].second;
        for(char j='1; j<='9; j++)
        {
            if(isValid(r, c, j, board))
            {
                board[r][c]=j;
                if(solve(board, pos, i+1))
                    return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {

        int n=board.size();
        vector<pair<int,int>> pos;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='.')
                    pos.push_back({i,j});
            }
        }
        solve(board, pos, 0);
    }
};
