#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int N){
	
	// Write your code here 

	vector<int> res;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	maxHeap.push(arr[0]);
	res.push_back(arr[0]);

	if(arr[1]>=arr[0])
	{
		minHeap.push(arr[1]);
		res.push_back((arr[0]+arr[1])/2);
	}
	else
	{
		minHeap.push(arr[0]);
		maxHeap.pop();
		maxHeap.push(arr[1]);
		res.push_back((arr[0]+arr[1])/2);
	}
	for(int i=2; i<N; i++)
	{
		int n=maxHeap.size();
		int m=minHeap.size();
		if(n==m)
		{
			if(arr[i]>=minHeap.top())
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
