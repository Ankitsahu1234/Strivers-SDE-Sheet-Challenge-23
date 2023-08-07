class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Method 1; Brute Force
      
        unordered_map<Node*, Node*> mp;
        Node *curr=head;
        while(curr!=NULL)
        {
            Node *newNode=new Node(curr->val);
            mp[curr]=newNode;
            curr=curr->next;
        }
        Node *t=head;
        while(t!=NULL)
        {
            Node *newNode=mp[t];
            newNode->next=(t->next!=NULL) ? mp[t->next] : NULL;
            newNode->random=(t->random!=NULL) ? mp[t->random] : NULL;
            t=t->next;
        }
        return mp[head];
    }
};
