class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Method 3: Efficient
        
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode *temp=head;
        int len=1;
        while(temp->next!=NULL)
        {
            len++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%len;
        int end=len-k;
        while(end--)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
