class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *curr=node;
        node->val=node->next->val;
        curr=node->next;
        node->next=curr->next;
        delete (curr);
    }
};
