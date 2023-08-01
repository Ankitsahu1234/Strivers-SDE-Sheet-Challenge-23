class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        // Method 4: Using Priority Queue (Min Heap)
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++)
        {
            pq.push({end[i], start[i]});
        }
        int prevEnd=pq.top().first;
        pq.pop();
        int count=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            if(it.second > prevEnd)
            {
                count++;
                prevEnd=it.first;
            }
        }
        return count;
    }
};

// bool myCmp(pair<int,int> &a, pair<int,int> &b)
// {
//     return a.second<b.second;
// }
// int maximumMeetings(vector<int> &start, vector<int> &end)
// {
//     // Write your code here.

//     // Method 1:
//     int n=start.size();
//     vector<pair<int, int>> temp;
//     int res=1;
//     for(int i=0; i<n; i++)
//     {
//         temp.push_back(make_pair(start[i], end[i]));
//     }
//     sort(temp.begin(), temp.end(), myCmp);
//     int prevEnd=temp[0].second;
//     for(int i=1; i<temp.size(); i++)
//     {
//         if(prevEnd<temp[i].first)
//         {
//             res++;
//             prevEnd=temp[i].second;
//         }
//     }
//     return res;
// }
