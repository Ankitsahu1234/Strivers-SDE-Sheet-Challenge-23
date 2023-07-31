/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x; 
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    
    vector<int> temp;
    Node *n=root;
    Node *b=root;
    while(n!=NULL)
    {
        temp.push_back(n->data);
        b=n->bottom;
        while(b!=NULL)
        {
            temp.push_back(b->data);
            b=b->bottom;
        }
        n=n->next;
    }
    sort(temp.begin(), temp.end());
    Node *head=new Node(temp[0]);
    Node *curr=head;
    for(int i=1; i<temp.size(); i++)
    {
        Node *newNode=new Node(temp[i]);
        curr->bottom=newNode;
        curr=curr->bottom;
    }
    return head;
}
