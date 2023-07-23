class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_set<int> myset;
        for(int x: nums)
        {
            if(myset.find(x)!=myset.end())
                return x;
            myset.insert(x);
        }
        return nums[0];
    }
};
