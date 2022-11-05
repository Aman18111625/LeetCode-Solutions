class Solution {
 class TrieNode{
      public:
        bool end;
        string word;
        TrieNode* children[26];
        TrieNode()
        {
            end=false;
            word="";
            for(int i=0;i<26;i++)
                children[i] = NULL;
        }
    };
    
public:
     void insert(string word,TrieNode* root)
    {
       TrieNode* temp=root;  
        for(int i=0;i<word.size();i++)
        {
         int k=word[i]-'a';
            if(temp->children[k] == NULL)
                  temp->children[k]=new TrieNode();
            temp=temp->children[k];
        }
        temp->end=true;
        temp->word=word;
    }
    
    vector<string>res; 
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>&board,int i,int j,TrieNode* root)
    {
        int n=board.size();
        int m=board[0].size();
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='.') return ;
        int k = board[i][j] - 'a';
        if(root->children[k] == nullptr)
            return;
        
        root=root->children[k];
        if(root->end)
        {
            res.push_back(root->word);
            root->end=false;
        }
        char c= board[i][j];
        board[i][j]='.';
        for(int d=0;d<4;d++)
        {
            int xx=i+dir[d][0];
            int yy=j+dir[d][1];
            dfs(board,xx,yy,root);
        }
        board[i][j]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
           res.clear();
        int n=board.size();
        if(n==0) return {};
        int m=board[0].size();
        TrieNode* root=new TrieNode();
        for(auto word: words)
             insert(word,root);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 dfs(board,i,j,root);
            }
        }
        return res;
    }
};