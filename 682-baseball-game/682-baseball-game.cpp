class Solution {
public:
    int calPoints(vector<string>& ops) {
         stack<int>st;
         int val1,val2;
         for(auto str: ops){
           if(str=="C"){
             st.pop();
           }else if(str=="D"){
              st.push(2*st.top());
           }
           else if(str=="+"){
               val1=st.top(); st.pop();
               val2=st.top(); 
              st.push(val1);
              st.push(val1+val2);
           }else {
             st.push(stoi(str)); 
           }
        }
        int sum=0;
        while(!st.empty()){
          sum+=st.top(); st.pop();
        }
        return sum;
    }
};
     
      