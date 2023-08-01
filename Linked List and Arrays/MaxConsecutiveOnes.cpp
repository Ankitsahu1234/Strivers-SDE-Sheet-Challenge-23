class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n=nums.size();
        int max_so_far=0;
        int curr_max=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
            {
                curr_max=curr_max+1;
                max_so_far=max(max_so_far, curr_max);
            }
            else 
                curr_max=0;
        }
        return max_so_far;
    }
};
