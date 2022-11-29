class RandomizedSet {
    vector<int>a;
    unordered_map<int,int>mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val)!=mpp.end()) return false;
        a.push_back(val);
        mpp[val]=a.size()-1; 
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end()) return false;
        else{
            int last=a.back();
            a[mpp[val]]=last;
            a.pop_back();
            mpp[last]=mpp[val];
            mpp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */