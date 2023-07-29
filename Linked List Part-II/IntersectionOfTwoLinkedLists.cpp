class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *curr1=headA, *curr2=headB;
        int n=0, m=0;
        while(curr1!=NULL)
        {
            curr1=curr1->next;
            n++;
        }
        while(curr2!=NULL)
        {
            curr2=curr2->next;
            m++;
        }
        int k;
        curr1=headA;
        curr2=headB;
        if(n>m)
        {
            k=n-m;
            while(curr1!=NULL && k--)
                curr1=curr1->next;
        }
        else if(n<m)
        {
            k=m-n;
            while(k-- && curr2!=NULL)
                curr2=curr2->next;
        } 
        if(curr1==curr2)
            return curr1;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            curr1=curr1->next;
            curr2=curr2->next;
            if(curr1==curr2)
                return curr1;
        }
        return NULL;
    }
};
