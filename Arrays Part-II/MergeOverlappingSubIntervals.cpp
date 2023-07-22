class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Sorting the Intervals in Increasing Order, based on their first value
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n=intervals.size();
        res.push_back(intervals[0]);
        for(int i=1; i<n; i++)
        {
            if(res.back()[1]>=intervals[i][0])
            {
                int start=res.back()[0];
                int end;
                if(res.back()[1]>=intervals[i][1])
                    end=res.back()[1];
                else    
                    end=intervals[i][1];
                res.pop_back();
                res.push_back({start, end});
            }
            else
            {
                int start=intervals[i][0];
                int end=intervals[i][1];
                res.push_back({start, end});
            }
        }
        return res;
    }
};
