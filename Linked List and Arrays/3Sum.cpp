class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        set<vector<int>> myset;
        for(int i=0; i<n; i++)
        {
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum<0)
                    left++;
                else if(sum>0)
                    right--;
                else
                {
                    vector<int> temp={nums[i], nums[left], nums[right]};
                    if(myset.find(temp)==myset.end())
                        res.push_back(temp);
                    myset.insert(temp);
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
