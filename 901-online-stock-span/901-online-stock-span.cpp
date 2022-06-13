class StockSpanner {
  stack<pair<int,int>>st;
  int i;
public:
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int ans=1;
        if(st.empty()){
          ans=1;
        }else{
          while(!st.empty() && st.top().first<=price) st.pop();
          if(st.empty()) ans=i+1;
          else ans=i-st.top().second;
        }
        st.push({price,i});
        i++;
       return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */