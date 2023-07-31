class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *curr=head;
        int len=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            len++;
        }
        k=k%len;
        if(k==0)
            return head;
        int count=0;
        ListNode *end=head;
        ListNode *ans=head->next;
        ListNode *last=head;
        while(count<k)
        {
            end=end->next;
            count++;
        }
        while(end->next!=NULL)
        {
            end=end->next;
            ans=ans->next;
            last=last->next;
        }
        end->next=head;
        last->next=NULL;
        return ans;
    }
};
