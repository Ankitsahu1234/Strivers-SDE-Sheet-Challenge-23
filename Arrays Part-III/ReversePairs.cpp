class Solution {
public:
    int cnt=0;
    void merge(vector<int> &arr, int low,int mid,int high) {
        int j=mid+1;
        // Additional for loop to count number of reversePairs
        for(int i=low; i<=mid; i++){
            while(j<=high && arr[i] > 2*(long long)arr[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        vector<int> temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high) {
            if(arr[left]<=arr[right]) {
                temp.push_back(arr[left++]);
            }
            else {
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid) {
            temp.push_back(arr[left++]);
        }
        while(right<=high) {
            temp.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++) {
            arr[i]=temp[i-low];
        }
    }
    void mergeSort(vector<int> &arr, int low,int high) {
        if(low==high) return;
        int mid=(low+high)>>1;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return cnt;
    }
};
