class Solution {
public:
    vector<int> temp;

    void helper(vector<int> &arr, int index, int target, vector<vector<int>> &res)
    {
        if(index==arr.size())
        {
            if(target==0)
                res.push_back(temp);
            return;
        }
        // Pick up the element
        if(arr[index]<=target)
        {
            temp.push_back(arr[index]);
            helper(arr, index, target-arr[index], res);
            temp.pop_back();
        }
        helper(arr, index+1, target, res);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        // Method 2:
        vector<vector<int>> res;
        helper(arr, 0, target, res);
        return res;
    }
};
