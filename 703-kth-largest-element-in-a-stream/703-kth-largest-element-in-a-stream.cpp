class KthLargest {
  /*
  priority_queue<int,vector<int>,greater<int>>pq;
  int size;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto it: nums)
        {
          pq.push(it);
          if(pq.size()>k) pq.pop();
        }
        size=k;
    }
    
    int add(int val) {
        pq.push(val);
      if(pq.size()>size) pq.pop();
      return pq.top();
    }*/
   public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int x:nums)add(x);
    }
    
    int add(int val) {
        if(minheap.size()<size)minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */