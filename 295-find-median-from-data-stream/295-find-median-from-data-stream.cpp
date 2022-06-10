class MedianFinder {
  //Time Complexity=> O(NLogN) Space Complexity=>O(N)
  /* ThughtProcess
    In the given example we have noticed that every time some value are less than median (left-Part) and some are greater than(Right-part)
    So what we'll do we can store these values in the ds for that we can use  priority_queue.PQ is nothing -> implementation of heaps->as we know heaps are two types=>1. max heap(top value is maximum) 2. min heap(top value is minimum)
    Here what we'll do -> we'll insert all the left value in minHeap & right value in the maxHeap.
    Here we need to  always keep  one thing in mind is that that size diff of both heap should be <=1 because we're finding middle value. 
  */
  priority_queue<int>maxHeap;
  priority_queue<int,vector<int>,greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
  //Here what we'll do -> we'll insert all the left value in minHeap & right value in the maxHeap.
 
        if(maxHeap.empty() || maxHeap.top()>num){
          maxHeap.push(num);
        }else minHeap.push(num);
       //   Here one thing we  have always need to keep in mind is that that size diff of both heap should be <=1 because we're finding middle value.
        if(maxHeap.size()>minHeap.size()+1){
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        }else if(minHeap.size()>maxHeap.size()+1){
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
    }
    
    double findMedian() {
//To find median we need to consider only top value. If size of both is equal than it means length of stream is even-> median is avg of top values of both pq.else if maxHeap.size()>minHeap-> median is top value of maxheap else minHeap.
        if(maxHeap.size()==minHeap.size())
        {
          double avg=(maxHeap.top()+minHeap.top())/2.0;
          return avg;
        }else if(maxHeap.size()>minHeap.size()) return maxHeap.top();
         else return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */