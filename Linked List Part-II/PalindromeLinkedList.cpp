class Solution {
public:
    bool isPal(vector<int> &temp)
    {
        int left=0, right=temp.size()-1;
        while(left<right)
        {
            if(temp[left]!=temp[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        
        vector<int> temp;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }
        if(isPal(temp))
            return true;
        return false;
    }
};
