#include <bits/stdc++.h>

bool myCmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.

    vector<pair<int,int>> temp;
    for(int i=0; i<start.size(); i++)
    {   
        temp.push_back({start[i], finish[i]});
    }
    sort(temp.begin(), temp.end(), myCmp);
    int prevEnd=temp[0].second;
    int count=1;
    for(int i=1; i<start.size(); i++)
    {
        if(temp[i].first>=prevEnd)
        {
            count++;
            prevEnd=temp[i].second;
        }
    }
    return count;
}
