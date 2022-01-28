class Trie {
    struct Node{
     Node* arr[26];
     bool flag;
    };
    Node* root;
public:
    Trie() {
       root=new Node(); 
    }
    
    void insert(string word) {
         Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']==NULL) temp->arr[word[i]-'a']=new Node();
            temp=temp->arr[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->arr[word[i]-'a']==NULL)return false;
             temp=temp->arr[word[i]-'a'];
        }
      return temp->flag;
    }
    
    bool startsWith(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
          if(temp->arr[word[i]-'a']==NULL)return false;
          temp=temp->arr[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */