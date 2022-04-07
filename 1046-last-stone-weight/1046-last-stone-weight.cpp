class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(auto &it : stones){
          maxHeap.push(it);
        }
        while(maxHeap.size()>1){
          int top1=maxHeap.top(); maxHeap.pop();
          int top2=maxHeap.top(); maxHeap.pop();
          if(top1==top2){
            continue;
          }else{
            maxHeap.push(top1-top2);
          }
        }
        if(maxHeap.empty()) return 0;
        return abs(maxHeap.top());
    }
};