/*
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
};*/
class MyHashSet {
private:
	vector<bool> table;
public:
	MyHashSet() : table(1e6 + 1, false) {}
	
	void add(int key) {
		table[key] = true;
	}
	
	void remove(int key) {
		table[key] = false;
	}
	
	bool contains(int key) {
		return table[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */