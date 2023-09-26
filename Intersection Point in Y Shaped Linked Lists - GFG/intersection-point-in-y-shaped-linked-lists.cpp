//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        Node *l1=head1, *l2=head2;
        int n1=0, n2=0;
        while(l1){
            n1++;
            l1=l1->next;
        }

        while(l2){
            n2++;
            l2=l2->next;
        }
        Node *temp1, *temp2;
        if(n1>n2){
            temp1=head1;
            temp2=head2;
            
        }else{
            temp1=head2;
            temp2=head1;
        }
        int diff=abs(n1-n2);
        //make distance from  temp1 and temp2 same to intersect point
        while(diff--){
            temp1=temp1->next;
        }

        //when temp1==temp2 the node is intersect node
        while(temp1 && temp2){
            if(temp1==temp2) return temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends