class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        // Removes all the Consecutive Duplicate elements from the Array or Vector
        auto it=unique(nums.begin(), nums.end());
        
        // We resized it to the iterator, pointing to the last element not being removed as a duplicate
        nums.resize(distance(nums.begin(), it));

        int n=nums.size();
        if(n==0 || n==1)
            return n;
        int maxLen=1;
        int max_so_far=1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]==nums[i-1]+1)
                maxLen++;
            else
                maxLen=1;
            max_so_far=max(max_so_far, maxLen);
        }
        return max_so_far;
    }
};
