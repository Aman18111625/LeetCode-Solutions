class Solution {
public:
  //In the 1st attempt I got WA because i mis-read the question 
  //Brute-Force Appraoch
  //TC:=>O(M*N)
  //SC:=>O(1)
    // int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    //     int cnt=0;
    //     for(auto num1: arr1){
    //        bool flag=true;
    //       for(auto num2: arr2){
    //         if(abs(num1-num2)<=d){
    //           flag=false;
    //         }
    //       }
    //       if(flag) cnt++;
    //     }
    //     return cnt;
    // }
  
    //Optimal Approach Using Binary Search
    //TC:=>O(N*LOGM)
    //SC:=>O(1)
     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       int cnt=0;
       sort(begin(arr2),end(arr2));//if array is sorted then we can apply BS that's why we sort the BS
       for(auto num1 : arr1){
         int low=0,high=arr2.size()-1;
         bool flag=true;
         while(low<=high){
           int mid=low+(high-low)/2;
           if(abs(num1-arr2[mid])<=d){
             flag=false; break;
           }else if(arr2[mid]>num1){
             high=mid-1;
           }else {
             low=mid+1;
           }
         }
         if(flag) cnt++;
       }
       return cnt;
     }
};