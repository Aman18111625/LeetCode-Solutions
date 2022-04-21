class MyHashSet {
public:
    unordered_map<int,int>mpp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mpp[key]++;
    }
    
    void remove(int key) {
       mpp.erase(key); 
    }
    
    bool contains(int key) {
        return mpp.find(key)!=mpp.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */