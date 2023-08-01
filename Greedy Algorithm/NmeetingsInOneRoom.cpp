bool myCmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second<b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.

    int n=start.size();
    vector<pair<int, int>> temp;
    int res=1;
    for(int i=0; i<n; i++)
    {
        temp.push_back(make_pair(start[i], end[i]));
    }
    sort(temp.begin(), temp.end(), myCmp);
    int prevEnd=temp[0].second;
    for(int i=1; i<temp.size(); i++)
    {
        if(prevEnd<temp[i].first)
        {
            res++;
            prevEnd=temp[i].second;
        }
    }
    return res;
}
