class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *curr1=l1, *curr2=l2;
        ListNode *head=new ListNode();
        ListNode *prev=head;
        int rem=0; 
        int sum=0;
        while(curr1!=NULL || curr2!=NULL)
        {   
            ListNode *temp=new ListNode();
            prev->next=temp;
            sum=0;
            sum+=rem;
            if(curr1!=NULL)
            {
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=NULL)
            {
                sum+=curr2->val;
                curr2=curr2->next;
            }
            if(sum<=9)
                temp->val=sum;
            else 
                temp->val=sum%10;
            prev=temp;
            if(sum>9)
                rem=sum/10;
            else
                rem=0;
        }
        if(rem!=0)
        {
            ListNode *temp=new ListNode();
            temp->val=rem;
            prev->next=temp;
        }
        return head->next;
    }
};
