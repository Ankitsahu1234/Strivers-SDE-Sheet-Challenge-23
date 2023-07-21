class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=nums[0];
        int max_so_far=nums[0];
      
        for(int i=1; i<n; i++)
        {
            maxi=max(maxi+nums[i], nums[i]);
            max_so_far=max(max_so_far, maxi);
        }
        return max_so_far;
    }
};
