#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here

  int n=arr.size();
  int maxLen=0;
  for(int i=0; i<n; i++)
  {
    int sum=arr[i];
    if(sum==0)
      maxLen=max(maxLen, 1);
    for(int j=i+1; j<n; j++)
    {
      sum+=arr[j];
      if(sum==0)
        maxLen=max(maxLen, j-i+1);
    }
  }
  return maxLen;
}
