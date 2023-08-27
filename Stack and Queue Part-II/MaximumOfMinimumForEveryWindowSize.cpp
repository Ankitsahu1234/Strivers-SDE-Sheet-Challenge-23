#include <bits/stdc++.h> 

vector<int> nextSmalllerIndexes(vector<int> &a, int n)
{
    stack<int> st;
    vector<int> nextSmaller(n, n);
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[i]<=a[st.top()])
            st.pop();
        if(!st.empty())
            nextSmaller[i]=st.top();
        st.push(i);
    }
    return nextSmaller;
}

vector<int> prevSmallerIndexes(vector<int> &a, int n)
{
    stack<int> st;
    vector<int> prevSmaller(n, -1);
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[i]<=a[st.top()])
            st.pop();
        if(!st.empty())
            prevSmaller[i]=st.top();
        st.push(i);
    }
    return prevSmaller;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    
    vector<int> nextSmaller=nextSmalllerIndexes(a, n);
    vector<int> prevSmaller=prevSmallerIndexes(a, n);
    vector<int> res(n, INT_MIN);
    for(int i=0; i<n; i++)
    {
        int size=nextSmaller[i]-prevSmaller[i]-1;
        res[size-1]=max(res[size-1], a[i]);
    }
    for(int i=n-2; i>=0; i--)
    {
        res[i]=max(res[i], res[i+1]);
    }
    return res;
}
