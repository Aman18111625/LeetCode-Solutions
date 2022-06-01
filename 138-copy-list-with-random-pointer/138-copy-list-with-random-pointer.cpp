/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          Node *iter=head,*front=head;
        //step1:- make copy of each node and link them in a linkedList
        while(iter)
        {
            front=iter->next;
            Node *copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        //step2:- assign random pointer for the copy nodes
        iter=head;
        while(iter)
        {
           if(iter->random)
           {
             iter->next->random=iter->random->next;
           }
            iter=iter->next->next;
        }
        //step3:-segregate copy and original linkedlist
        iter=head;
        Node *dummy=new Node(0);
        Node *temp=dummy;
        while(iter)
        {
            front=iter->next->next;
            //extract the copy
            temp->next=iter->next;
            iter->next=front;
            
            temp=temp->next;
            iter=front;
        }
        return dummy->next;
    }
};