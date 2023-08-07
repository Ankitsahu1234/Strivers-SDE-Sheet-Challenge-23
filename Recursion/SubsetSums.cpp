class Solution
{
public:
    void helper(vector<int> &arr, int sum, int index, vector<int> &res)
    {
        if(index==arr.size())
        {
            res.push_back(sum);
            return;
        }
        helper(arr, sum+arr[index], index+1, res);  // Pick
        helper(arr, sum, index+1, res);     // Do not Pick
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        
        vector<int> res;
        int sum=0;
        helper(arr, sum, 0, res);
        return res;
    }
};
