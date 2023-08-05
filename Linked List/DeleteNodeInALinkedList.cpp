class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *curr=node;
        node->val=node->next->val;
        curr=curr->next;
        node->next=node->next->next;
        delete (curr);
    }
};
