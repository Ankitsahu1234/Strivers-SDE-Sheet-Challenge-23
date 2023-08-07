class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // Method 2: Efficient
        
        Node *temp=head;
        // Step 1
        while(temp!=NULL)
        {
            Node *newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        // Step 2
        Node *itr=head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
                itr->next->random=itr->random->next;
            itr=itr->next->next;
        }
        Node *dummy=new Node(0);
        itr=head;
        temp=dummy;
        Node *fast;
        while(itr!=NULL)
        {
            fast=itr->next->next;
            temp->next=itr->next;
            itr->next=fast;
            temp=temp->next;
            itr=fast;
        }
        return dummy->next;
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {

//         // Method 1; Brute Force
      
//         unordered_map<Node*, Node*> mp;
//         Node *curr=head;
//         while(curr!=NULL)
//         {
//             Node *newNode=new Node(curr->val);
//             mp[curr]=newNode;
//             curr=curr->next;
//         }
//         Node *t=head;
//         while(t!=NULL)
//         {
//             Node *newNode=mp[t];
//             newNode->next=(t->next!=NULL) ? mp[t->next] : NULL;
//             newNode->random=(t->random!=NULL) ? mp[t->random] : NULL;
//             t=t->next;
//         }
//         return mp[head];
//     }
// };
