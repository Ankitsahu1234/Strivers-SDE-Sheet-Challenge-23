class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    vec.push_back(make_pair(i, j));
                }
            }
        }
        for(int i=0; i<vec.size(); i++)
        {
            pair<int, int> p=vec[i];
            int x=p.first;
            int y=p.second;
            for(int j=0; j<m; j++)
            {
                matrix[x][j]=0;
            }
            for(int j=0; j<n; j++)
            {
                matrix[j][y]=0;
            }
        }
    }
};
