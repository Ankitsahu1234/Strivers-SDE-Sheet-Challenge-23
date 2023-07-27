#include <bits/stdc++.h>

int subarraysWithSumK(vector < int > A, int B) {
    // Write your code here

    int n=A.size();
    int xr=0, cnt=0;
    unordered_map<int, int> mp;
    mp[xr]++;   // for {0,1}
    for(int i=0; i<n; i++)
    {
        xr=xr^A[i];
        int x=xr^B;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}
