int countSmallerThanMid(vector<int> &row, int mid)
{
    int l=0, h=row.size()-1;
    while(l<=h)
    {
        int md=(l+h)>>1;
        if(row[md]<=mid)
            l=md+1;
        else    
            h=md-1;
    }
    return l;
}

int median(vector<vector<int>> &mat, int n, int m) {
    // Write your code here.

    int low=1;
    int high=1e9;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            cnt+=countSmallerThanMid(mat[i], mid);
        }
        if(cnt<=(n*m)/2)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
