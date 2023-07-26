class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Method 2: Single Pass Hash Table
        
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            int complement=target-nums[i];
            if(mp.count(complement))
                return {mp[complement], i};
            mp[nums[i]]=i;
        }
        return {};
    }
};
