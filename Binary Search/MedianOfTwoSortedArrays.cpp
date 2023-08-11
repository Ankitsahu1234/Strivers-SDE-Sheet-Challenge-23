class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> temp;
        for(int x: nums1)
            temp.push_back(x);
        for(int x: nums2)
            temp.push_back(x);
        int n=temp.size();
        sort(temp.begin(), temp.end());
        if(n%2!=0)
            return temp[n/2];
        else
            return (temp[n/2]+temp[n/2-1])/2.0;
    }
};
