class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next==NULL)
            return NULL;
        int len=0;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            curr=curr->next;
            len++;
        }
        ListNode *prev=NULL;
        curr=head;
        if(n==len)
        {
            curr=curr->next;
            delete head;
            return curr;
        }
        int k=len-n;
        while(k--)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete (curr);
        return head;
    }
};
