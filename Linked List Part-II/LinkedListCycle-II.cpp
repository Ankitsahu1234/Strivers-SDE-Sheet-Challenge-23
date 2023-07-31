class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> myset;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(myset.find(curr)!=myset.end())
                return curr;
            myset.insert(curr);
            curr=curr->next;
        }
        return NULL;
    }
};
