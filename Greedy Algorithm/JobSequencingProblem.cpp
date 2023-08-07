bool myCmp(vector<int> &v1, vector<int> &v2)
{
    if(v1[2]==v2[2])
        return v1[1]>v2[1];
    return v1[2]>v2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), myCmp);
    int maxi=jobs[0][1];
    for(int i=1; i<n; i++)
    {      
        maxi=max(maxi, jobs[i][1]);
    }
    int slot[maxi+1];
    memset(slot, -1, sizeof(slot));
    int countJobs=0, jobProfit=0;
    for(int i=0; i<n; i++)
    {
        for(int j=jobs[i][1]; j>0; j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                countJobs++;
                jobProfit+=jobs[i][2];
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}
