long long func(int b, int exp)
{
    long long ans=1;
    long long base=b;
    while(exp>0)
    {
        if(exp%2)
        {
            exp--;
            ans=ans*base;
        }
        else
        {
            exp/=2;
            base=base*base;
        }
    }
    return ans;
}
int NthRoot(int n, int m) {
    // Write your code here.

    for(int i=1; i<=m; i++)
    {
        long long val=func(i, n);
        if(val==m*1ll)
            return i;
        else if(val>m*1ll)
            break;
    }
    return -1;
}
