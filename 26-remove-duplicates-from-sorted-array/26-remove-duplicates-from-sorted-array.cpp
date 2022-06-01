class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
          int n=arr.size();
//         set<int>st;
//         for (int i = 0; i < n; i++) st.insert(arr[i]);
  
//         int k = st.size();
//         int j = 0;
//         for (int x: st) arr[j++] = x;
//         return k;
             int i = 0;
           for (int j = 1; j < n; j++) {
             if (arr[i] != arr[j]) {
                  i++;
              arr[i] = arr[j];
             } 
           }
           return i + 1;
    }
};