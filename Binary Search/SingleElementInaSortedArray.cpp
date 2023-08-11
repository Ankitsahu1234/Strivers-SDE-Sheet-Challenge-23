class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Method 2: Using XOR
        int res=0;
        for(int i=0; i<nums.size(); i++)
        {
            res=res^nums[i];
        }
        return res;
    }
};
