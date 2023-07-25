class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Method 2: Using Moore's Voting Algorithm
        int n=nums.size();
        int cnt=0;
        int ele;

        // Moore's Voting Algorithm
        for(int i=0; i<n; i++)
        {
            if(cnt==0)
            {
                cnt=1;
                ele= nums[i];
            }
            else if(ele==nums[i])
                cnt++;
            else
                cnt--;
        }
        
        // This is for checking if the ele is Majority element or not
        int cnt2=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==ele)
                cnt2++;
        }
        if(cnt2>n/2)
            return ele;
        return -1;
    }
};
