/*
class MyHashMap {
    int mpp[1000001];
public:
    MyHashMap() {
       fill(mpp,mpp+1000000,-1);
    }
    
    void put(int key, int value) {
       mpp[key]=value;
    }
    
    int get(int key) {
      return mpp[key];
    }
    
    void remove(int key) {
     mpp[key]=-1;
    }
};*/
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int,int>>> um;
    int size = 769; // Generally a large prime number
	
	MyHashMap() {
        um.resize(size);
    }
	
	int getInd(int key)
    {
        return key%size;
    }
    
    void put(int key, int value) {
        int ind = getInd(key);
        auto& list = um[ind];
        //check if key already inserted in map or not
        for(auto &i:list)
        {
            if(i.first==key)
            {
               // cout<<"hi"<<endl;
                i.second=value;
                return;
            }
        }
        //if not then insert
        list.push_back({key,value});
    }
    
    
    int get(int key) {
       int ind = getInd(key);
       auto& list = um[ind];
       for(auto i:list)
       {
           if(i.first==key)
               return i.second;
       }
       return -1;
    }
    
    void remove(int key) {
        int ind = getInd(key);
        auto& list = um[ind];
        for(auto i:list)
        {
            if(i.first==key)
            {
                list.remove(i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */