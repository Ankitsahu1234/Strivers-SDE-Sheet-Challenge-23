#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
    // Write your code here 
  
    int start=0, end=0;
  	sort(A.begin(), A.end());
  	vector<int> vec(n+1, 0);
    for(int i=0; i<n; i++)
        vec[A[i]]++;
  	int count=0;
  	for(int i=1; i<=n; i++)
  	{
    		if(vec[i]>1)
    		{
    			count++;
    			end=i;
    			if(count==2)
    				break;
    		}
    		else if(vec[i]==0)
    		{
    			count++;
    			start=i;
    			if(count==2)
    				break;
    		}
	  }
    return make_pair(start, end);
}
