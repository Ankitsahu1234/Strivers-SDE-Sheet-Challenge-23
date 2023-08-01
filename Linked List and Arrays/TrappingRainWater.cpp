class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        int res=0;
        vector<int> lMax(n, 0);
        vector<int> rMax(n, 0);
        lMax[0]=height[0];
        for(int i=1; i<n; i++)
        {
            lMax[i]=max(lMax[i-1], height[i]);
        }
        rMax[n-1]=height[n-1];
        for(int j=n-2; j>=0; j--)
        {
            rMax[j]=max(rMax[j+1], height[j]);
        }
        for(int i=1; i<n; i++)
        {
            int LRMin=min(lMax[i], rMax[i]);
            res+=max(0, (LRMin-height[i]));
        }
        return res;
    }
};
