class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        // Edge cases
        if(n==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int low=1, high=n-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // If nums[mid] is the single element
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            // We are in the left:
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]))
            {
                // Eliminate the left half
                low=mid+1;
            }
            // We are in the right:
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {

//         // Method 2: Using XOR
//         int res=0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             res=res^nums[i];
//         }
//         return res;
//     }
// };
