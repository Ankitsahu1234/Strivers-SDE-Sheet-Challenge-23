bool isSafe(vector<vector<int>> &mat, int node, int color[], int col)
{
    for(int k=0; k<mat.size(); k++)
    {
        if(k!=node && mat[k][node]==1 && color[k]==col)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &mat, int node, int color[], int m)
{
    if(node==mat.size())
        return true;
    for(int i=1; i<=m; i++)
    {
        if(isSafe(mat, node, color, i))
        {
            color[node]=i;
            if(solve(mat, node+1, color, m))
                return true;
            color[node]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here

    int v=mat.size();
    int color[v]={0};
    if(solve(mat, 0, color, m))
        return "YES";
    return "NO";
}
