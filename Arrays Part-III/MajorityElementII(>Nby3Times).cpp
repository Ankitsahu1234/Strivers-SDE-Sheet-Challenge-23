class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // There can be atmost 2 elements that can appear more than n/3 times

        // applying the Extended Boyer Moore's Voting Algorithm:
        int n=nums.size();
        int cnt1=0, cnt2=0;
        int ele1=INT_MIN, ele2=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
                cnt1++;
            else if(nums[i]==ele2)
                cnt2++;
            else 
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        // Manually check if the stored elements in
        // ele1 and ele2 are the majority elements:
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++)
        {
            if(ele1==nums[i])   
                cnt1++;
            else if(ele2==nums[i])
                cnt2++;
        }
        if(cnt1 > n/3)
            res.push_back(ele1);
        if(cnt2 > n/3)
            res.push_back(ele2);
        sort(res.begin(), res.end());
        return res;
    }
};
