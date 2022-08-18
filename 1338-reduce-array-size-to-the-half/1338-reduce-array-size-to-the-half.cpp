class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>map;
        for(auto it: arr){
          map[it]++;
        }
        priority_queue<int>maxHeap;
        for(auto it: map){
           maxHeap.push(it.second);
        }
        int n=arr.size(),x=n,ans=0;
        n>>=1;
        while(x>n && !maxHeap.empty()){
           x-=maxHeap.top();
           ans++;
           maxHeap.pop();
        }
        return ans;
    }
};

