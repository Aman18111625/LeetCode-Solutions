class LRUCache {
public:
    class node{
        public:
       int key;
                     int val;
       node* next;
       node* prev;
       node(int key_,int val_)
       {
           key=key_;
           val=val_;
       }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*>m;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    

    
    void deletenode(node* delnode)
    {
        node* delpre=delnode->prev;
        node* delnext=delnode->next;
        delpre->next=delnext;
        delnext->prev=delpre;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* exist=m[key];
            m.erase(key);
            deletenode(exist);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */