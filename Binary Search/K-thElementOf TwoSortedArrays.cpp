class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> temp;
        for(int i=0; i<n; i++)
            temp.push_back(arr1[i]);
        for(int i=0; i<m; i++)
            temp.push_back(arr2[i]);
        sort(temp.begin(), temp.end());
        return temp[k-1];
    }
};
