class Solution {
public:
    int lengthOfLL(ListNode *head)
    {
        int n=0;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            n++;
            curr=curr->next;
        }
        return n;
    }
    ListNode* solve(ListNode *head, int k, int sz)
    {
        if(sz<k)
            return head;
        if(head==NULL)
            return NULL;
        ListNode *prev=head, *curr=head, *nxt;
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt++;
        }
        head->next=solve(nxt, k, sz-k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int n=lengthOfLL(head);
        return solve(head, k, n);
    }
};
