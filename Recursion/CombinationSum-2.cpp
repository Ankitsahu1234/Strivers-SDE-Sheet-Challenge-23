class Solution {
    vector<int> temp;
public:

    void backtrack(vector<int> &arr, int index, int curr_sum, int target, vector<vector<int>> &res)
    {
        if(curr_sum==target)
        {
            res.push_back(temp);
            return;
        }
        else if(curr_sum>target)
            return;
        for(int i=index; i<arr.size(); i++)
        {
            if(i>index && arr[i]==arr[i-1])
                continue;
            temp.push_back(arr[i]);
            curr_sum+=arr[i];
            backtrack(arr, i+1, curr_sum, target, res);
            temp.pop_back();
            curr_sum-=arr[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        backtrack(arr, 0, 0, target, res);
        return res;
    }
};
