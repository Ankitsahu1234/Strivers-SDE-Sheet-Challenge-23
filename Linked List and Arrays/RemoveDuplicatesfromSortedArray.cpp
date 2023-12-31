class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Method 2:
        int n=nums.size();
        auto it=unique(nums.begin(), nums.end());
        // nums.resize(distance(nums.begin(), it));
        return it-nums.begin();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Method 3: Efficient (2 pointer)
        int n=nums.size();
        int i=0;
        for(int j=1; j<n; j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {

//         // Method 1:
//         int n=nums.size();
//         if(n==1)
//             return n;
//         vector<int> temp;
//         bool flag=false;
//         for(int i=0; i<n-1; i++)
//         {
//             if(nums[i]!=nums[i+1])
//             {
//                 flag=true;
//                 temp.push_back(nums[i]);
//             }
//             if(i==n-2 && nums[n-2]==nums[n-1])
//                 temp.push_back(nums[i]);
//         }
//         if(flag==false)
//             return 1;
//         if(nums[n-1]!=nums[n-2])
//             temp.push_back(nums[n-1]);
//         for(int i=0; i<temp.size(); i++)
//         {
//             nums[i]=temp[i];
//         }
//         return temp.size();
//     }
// };
