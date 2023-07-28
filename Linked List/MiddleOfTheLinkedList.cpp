class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Method 3: [Efficient] Tortoise-Hare-Approach
        
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
