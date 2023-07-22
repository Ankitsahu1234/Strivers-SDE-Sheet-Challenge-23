class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int nextGreater[n];
        nextGreater[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--)
        {
            nextGreater[i]=max(prices[i], nextGreater[i+1]);
        }
        int ans=0;
        for(int i=0; i<n-1; i++)
        {
            ans=max(ans, nextGreater[i]-prices[i]);
        }
        return ans;
    }
};
