#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for(int i=0; i<n; i++)
    {
        if(q[i][0]==0)
        {
            pq.push(q[i][1]);
        }
        else
        {
            res.push_back(pq.top());
            pq.pop();
        }
    }
    return res;
}


// #include <bits/stdc++.h> 

// void heapify(vector<int> &arr, int n, int i)
// {
//     int largest=i;
//     int left=2*i+1;
//     int right=2*i+2;
//     if(left<=n-1 && arr[largest]>arr[left])
//         largest=left;
//     if(right<=n-1 && arr[largest]>arr[right]) 
//         largest=right;
//     if(largest!=i)
//     {
//         swap(arr[largest], arr[i]);
//         heapify(arr, n, largest);
//     }
// }
// void buildHeap(vector<int> &arr, int n)
// {
//     for(int i=(n-1)/2; i>=0; i--)
//     {
//         heapify(arr, n, i);
//     }
// }
// void MinHeap(vector<int> &arr)
// {
//     int n=arr.size();
//     buildHeap(arr, n);
//     for(int i=n-1; i>=0; i--)
//     {
//         swap(arr[i], arr[0]);
//         heapify(arr, i, 0);
//     }
// }

// void insert(vector<int> &arr, int ele)
// {
//     arr.push_back(ele);
//     MinHeap(arr);
// }

// vector<int> minHeap(int n, vector<vector<int>>& q) {
//     // Write your code here.

//     vector<int> arr;
//     vector<int> res;
//     for(int i=0; i<n; i++)
//     {
//         if(q[i][0]==0)
//         {
//             insert(arr, q[i][1]);
//         }
//         else
//         {
//             res.push_back(arr.back());
//             arr.pop_back();
//         }
//     }
//     return res;
// }
