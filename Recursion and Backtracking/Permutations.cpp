class Solution {
public:
    void permute(vector<int> &nums, int index, int n, vector<vector<int>> &res)
    {
        if(index==n)
        {
            res.push_back(nums);
            return;
        }
        for(int i=index; i<n; i++)
        {
            swap(nums[i], nums[index]);
            permute(nums, index+1, n, res);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n=nums.size();
        permute(nums, 0, n, res);
        return res;
    }
};
