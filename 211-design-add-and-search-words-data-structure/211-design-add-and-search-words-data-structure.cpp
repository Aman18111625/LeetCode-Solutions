class Trie{
  public:
   vector<Trie*>arr;
   bool flag;
   Trie(){
      arr.resize(26);
      for(auto &it : arr) it=NULL;
      flag=false;
   }
};


class WordDictionary {
   Trie* root;
public:
    WordDictionary() {
        root=new Trie();
    }
    
  
    void addWord(string word) {
       Trie* temp=root;
       for(auto &ch: word)
       {
         if(!temp->arr[ch-'a'])
         {
            temp->arr[ch-'a']=new Trie(); 
         }
          temp=temp->arr[ch-'a'];
       }
        temp->flag=true;
    }
    
    bool search(string word) {
      return helper(word,root);
    }
  
    bool helper(string word,Trie* temp)
    {
        for(int i=0;i<word.size();i++)
        {
          char ch=word[i];
          if(ch=='.')
          {
            for(auto &it : temp->arr)
            {
                if(it && helper(word.substr(i+1),it)) return true;
            }
            return false;
          }else if(!temp->arr[ch-'a']) return false;
          else temp=temp->arr[ch-'a'];
        }
      return temp->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 **/



    
  
    
  
    
   
