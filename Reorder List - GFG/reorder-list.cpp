//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    // Your code here
    Node* reverse(Node* head){
       if(!head) return head;
       Node* newHead=NULL;
       Node* curr=head;
       while(curr){
          Node* nex=curr->next;
          curr->next=newHead;
          newHead=curr;
          curr=nex;
        }
        return newHead;
    }

    void reorderList(Node* head) {
    // Your code here
      if(!head or !head->next) return ;
      Node* head1=head,*slow=head,*fast=head,*head2;
      while(fast->next and fast->next->next){
          slow=slow->next;
          fast=fast->next->next;
       }
      Node*temp=slow->next;
      slow->next=NULL;
      head2=reverse(temp);
      Node*fi=new Node(-1);
      Node *final=fi;
    while(head1 || head2){
      if(head1){
       final->next=head1;
       final=final->next;
       head1=head1->next;  
      }
      if(head2){
       final->next=head2;
       final=final->next;
       head2=head2->next;
      }
    }
    head=final->next;
}
        
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends