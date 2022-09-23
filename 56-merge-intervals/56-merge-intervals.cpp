class Solution {
public:
    //Brute Force Solution  -> Accepted
   //TC:->O(N^2) 
  //Auxiliary Space:-> O(1)
  //Approach:->Simply run two for loop and merge the intervals that are overlapping
    //   vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     int len=intervals.size();
    //     if(len<=1) return intervals;
    //     sort(intervals.begin(),intervals.end()); //Time taken by sort() is O(NlogN)
    //     vector<vector<int>> res;
    //     for(int i=0;i<len;i++){
    //         int a=intervals[i][0];
    //         int b=intervals[i][1];
    //         //for loop inside for loop takes time of O(N^2)
    //         for(int j=i+1;j<len;j++){
    //             int c=intervals[j][0];
    //             int d=intervals[j][1];
    //             if(b>=c){ //if end of prev interval >= start of next interval
    //                 b=max(b,d);
    //                 // i pointer should now point to the pair pointed by j 
    //                 // and in next iteration of j loop, j will point to the 
    //                 // pair next to the one pointed by this i
    //                 i=j;
    //             }
    //         } 
    //         res.push_back({a,b});
    //     }
    //     return res;
    // }
  
  //optimized Soltion
  //Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our data structure.
  //Time-Complexity:=>O(N)
  //Space-Complexity:=>O(N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeIntervals;//to store ans
        if(intervals.empty()) return mergeIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval=intervals[0];
        for(auto it:intervals){
          if(it[0]<=tempInterval[1]) {
           tempInterval[1]=max(it[1],tempInterval[1]);
          }
          else{
           mergeIntervals.push_back(tempInterval);
           tempInterval=it;
          }
        }
        //for last interval
        mergeIntervals.push_back(tempInterval);
        return mergeIntervals;
    }
};