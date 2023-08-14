#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int N){
	
	// Write your code here 

	vector<int> res;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int i=0; i<N; i++)
	{
		int n=maxHeap.size();
		int m=minHeap.size();
		if(n==m)
		{
			if(m!=0 && arr[i]>=minHeap.top())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(arr[i]);
			}
			else
			{
				maxHeap.push(arr[i]);
			}
		}
		else if(n>m)
		{
			if(arr[i]>=maxHeap.top())
			{
				minHeap.push(arr[i]);
			}
			else
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(arr[i]);
			}
		}
		n=maxHeap.size();
		m=minHeap.size();
		if(n==m)
		{
			int x=maxHeap.top();
			int y=minHeap.top();
			res.push_back((x+y)/2);
		}
		else if(n>m)
		{
			int x=maxHeap.top();
			res.push_back(x);
		}
	}
	return res;
}
