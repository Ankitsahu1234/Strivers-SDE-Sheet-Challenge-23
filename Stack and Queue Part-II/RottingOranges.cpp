class Solution {
    int delRow[4]={-1, 0, 1, 0};
    int delCol[4]={0, 1, 0, -1};
    
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                    q.push({i, j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
        int ans=-1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto p=q.front();
                q.pop();
                int row=p.first;
                int col=p.second;
                for(int i=0; i<4; i++)
                {
                    int nrow=row+delRow[i];
                    int ncol=col+delCol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                    {
                        grid[nrow][ncol]=2;
                        q.push({nrow, ncol});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0)
            return -1;
        if(ans==-1)
            return 0;
        return ans;
    }
};
