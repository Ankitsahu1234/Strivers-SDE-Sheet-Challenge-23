#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n=kArrays.size();
    for(int i=0; i<n; i++)
    {
        int m=kArrays[i].size();
        for(int j=0; j<m; j++)
        {
            minHeap.push(kArrays[i][j]);
        }
    }
    while(!minHeap.empty())
    {
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    return res;
}
