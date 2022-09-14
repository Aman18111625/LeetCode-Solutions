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
  //Approach-1:->Using hashmap
  //traversing all the root to leaf path and checking the number of odd freq element is <=1 then it can be pseudo-palindrome else not a pseduo-palindrome.
  //TC:=>O(N)
  //SC:=>O(N)
//     int res=0;
//     void countRootToLeafPath(TreeNode* root,unordered_map<int,int>&map){
//       if(!root) return ;
//       map[root->val]++;
//       //if root is a leaf node
//       if(!root->left && !root->right){
//         int count=0;
//         for(auto it: map){
//           if(it.second%2==1) count++;
//         }
//         if(count<=1) res++;
//         map[root->val]--;
//         return ;
//       }
//       if(root->left) 
//          countRootToLeafPath(root->left,map);
//       if(root->right)
//          countRootToLeafPath(root->right,map);
//       map[root->val]--;
//     }
  
  
//     int pseudoPalindromicPaths (TreeNode* root) {
//       if(!root) return 0;
//       unordered_map<int,int>map;
//       countRootToLeafPath(root,map);
//       return res;
//     }
  
  //Approach-2 :->Using Set
  //traverse all the root to leaf node and if any element is in set then we'll remove else we'll insert into it .At the end  set basically contains only those elements that have occurred odd no. of times yet. On reaching leaf, we check if size of set<=1 i.e. it is a pseudo palindrome
    int res=0;
    void countRootToLeafPath(TreeNode* root,unordered_set<int>s){
      if(!root) return ;
      if(s.count(root->val)){
        s.erase(root->val);
      }else{
        s.insert(root->val);
      }
      //if root is a leaf node
      if(!root->left && !root->right){
        if(s.size()<=1) res++;
        return ;
      }
      if(root->left) 
         countRootToLeafPath(root->left,s);
      if(root->right)
         countRootToLeafPath(root->right,s);
    }
  
  
    int pseudoPalindromicPaths (TreeNode* root) {
      if(!root) return 0;
      unordered_set<int>s;
      countRootToLeafPath(root,s);
      return res;
    }
};