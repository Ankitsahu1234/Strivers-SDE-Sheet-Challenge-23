class Solution {
    vector<int> temp;
public:
    void findSubsets(vector<int> &nums, int index, vector<vector<int>> &ans) {
         ans.push_back(temp);
         for (int i = index; i < nums.size(); i++) 
         {
            if (i != index && nums[i] == nums[i - 1]) 
                continue;
            temp.push_back(nums[i]);
            findSubsets(nums, i+1, ans);
            temp.pop_back();
        }
    }
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // Method 2: Efficient

        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, ans);
        return ans;
    }
};
