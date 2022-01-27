/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        TreeNode *new_node = new TreeNode();
        ListNode *lo = head, *hi = head, *prev;
		
        while(hi -> next && hi -> next -> next) {
            hi = hi -> next -> next;
            prev = lo;
            lo = lo -> next;
        }
		
        new_node -> val = lo -> val;
        if(prev) {
            prev -> next = NULL;
            new_node -> left = sortedListToBST(head);
        }
        if(lo -> next) {
            new_node -> right = sortedListToBST(lo -> next);
        }
		
        return new_node;
    }
};