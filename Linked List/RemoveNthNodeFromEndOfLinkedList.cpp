class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Method 2: Efficient: 2 Pointer Approach

        ListNode *start=new ListNode();
        start->next=head;
        ListNode *slow=start;
        ListNode *fast=start;
        for(int i=1; i<=n; i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         if(head->next==NULL)
//             return NULL;
//         int len=0;
//         ListNode *curr=head;
//         while(curr!=NULL)
//         {
//             curr=curr->next;
//             len++;
//         }
//         ListNode *prev=NULL;
//         curr=head;
//         if(n==len)
//         {
//             curr=curr->next;
//             delete head;
//             return curr;
//         }
//         int k=len-n;
//         while(k--)
//         {
//             prev=curr;
//             curr=curr->next;
//         }
//         prev->next=curr->next;
//         delete (curr);
//         return head;
//     }
// };
