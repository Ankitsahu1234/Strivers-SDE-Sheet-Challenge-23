class Solution {
public:

    ListNode* merge(ListNode *list1, ListNode *list2)
    {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        vector<ListNode*> temp;
        ListNode *curr1=list1, *curr2=list2;
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->val <= curr2->val)
            {
                temp.push_back(curr1);
                curr1=curr1->next;
            }
            else
            {
                temp.push_back(curr2);
                curr2=curr2->next;
            }
        }
        while(curr1!=NULL)
        {
            temp.push_back(curr1);
            curr1=curr1->next;
        }
        while(curr2!=NULL)
        {
            temp.push_back(curr2);
            curr2=curr2->next;
        }
        ListNode *head=temp[0];
        ListNode *curr=head;
        for(int i=1; i<temp.size(); i++)
        {
            curr->next=temp[i];
            curr=curr->next;
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *head=merge(list1, list2);
        return head;
    }
};
