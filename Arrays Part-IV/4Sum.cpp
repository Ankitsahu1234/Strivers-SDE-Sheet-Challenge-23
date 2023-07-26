class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Solved using Array(Three Nested Loop) + Sorting + Hash Table(set)
      
        int n=nums.size();
        vector<vector<int>> res;
        set<vector<int>> myset;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                long long newTarget=(long long)target-(long long)nums[i]-(long long)nums[j];
                int low=j+1, high=n-1;
                while(low<high)
                {
                    if(nums[low]+nums[high] < newTarget)
                        low++;
                    else if(nums[low]+nums[high] > newTarget)
                        high--;
                    else
                    {
                        myset.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    }
                }
            }
        }
        for(vector<int> vec: myset)
        {
            res.push_back(vec);
        }
        return res;
    }
};
