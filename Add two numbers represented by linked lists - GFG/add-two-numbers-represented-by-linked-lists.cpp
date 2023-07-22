//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:


     struct Node* reverseList(Node *head){
        struct Node* current=head;
        struct Node* prev=NULL;
        struct Node* next=NULL;
         
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* ans=new Node(-1);
        Node* dummy=ans;
        first=reverseList(first),second=reverseList(second);
        int carry=0;
        while(first != NULL || second != NULL){
            
            int val=carry;
            if(first != NULL){
                val+=first->data;
                first=first->next;
            }
            if(second != NULL){
                val+=second->data;
                second=second->next;
            }
            carry=val/10;
            struct Node* newnode=new Node(val%10);
            ans->next=newnode;
            ans=newnode;
        }
        
        if(carry ){
            struct Node* newnode=new Node(carry);
            ans->next=newnode;
            ans=newnode;
        }
        ans=reverseList(dummy->next);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends