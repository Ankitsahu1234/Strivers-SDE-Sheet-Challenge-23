class Solution {
public:

    ListNode* reverse(ListNode *node)
    {
        ListNode *prev=NULL, *curr=node, *nxt;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return true;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode *dummy=head;
        while(slow!=NULL)
        {
            if(slow->val!=dummy->val)
                return false;
            slow=slow->next;
            dummy=dummy->next;
        }
        return true;
    }
};
