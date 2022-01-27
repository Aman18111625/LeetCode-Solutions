class Solution {
public:
    struct Trie{
      Trie *bit[2];
      Trie(){
        bit[0]=NULL;
        bit[1]=NULL;
      }
    };
    
   void insert(Trie* root,int num){
     Trie* curr=root;
     for(int i=31;i>=0;i--){
       //get the ith bit
       int b=((num>>i)&1);
       if(curr->bit[b]==NULL){
         curr->bit[b]=new Trie();
       }
       curr=curr->bit[b];
     }
   } 
  
    void solve(Trie* root,int num,int &res){
      int curr_xor=0;
      Trie* curr=root;
      for(int i=31;i>=0;i--)
      {
        int curr_bit=((num>>i)&1);
        int need=(curr_bit)?0:1;
        if(curr->bit[need]){
          curr_xor<<=1;
          curr_xor|=1;
          curr=curr->bit[need];
        }else{
          curr_xor<<=1;
          curr=curr->bit[curr_bit];
        }
      }
      res=max(res,curr_xor);
    }
  
  
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        Trie* root=new Trie();
        for(int i=0;i<n;i++){
          insert(root,nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            solve(root,nums[i],ans);
      
        return ans;
    }
};

   
  