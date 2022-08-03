class MyCalendar {
  unordered_map<int,int>map;
public:
    MyCalendar() {
        map.clear();
    }
    
    bool book(int s1, int e1) {
        for(auto &it : map){
          int s2=it.first;
          int e2=it.second;
          if(!(s2>=e1 or s1>=e2)) return false;
        }
        map[s1]=e1;
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */