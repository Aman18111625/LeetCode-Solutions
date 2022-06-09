class Solution {
public:
    //Brute-Force :->Generate all the pairs and find max distance
    //TC:=>O(N*M)
    //SC:=>O(1)
    // int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    //     int ans=INT_MIN;
    //     int n=nums1.size(),m=nums2.size();
    //     for(int i=0;i<n;i++){
    //       for(int j=0;j<m;j++){
    //            if(i<=j && nums1[i]<=nums2[j]) ans=max(ans,j-i); 
    //       }
    //     }
    //    return ans==INT_MIN?0:ans;
    // }
   int maxDistance(vector<int>& nums1, vector<int>& nums2){
       int i=0,j=0;
       int ans=0;
       int n=nums1.size(),m=nums2.size();
       while(i<n && j<m){
          if(nums1[i]>nums2[j]) ++i;
          else {
            ans=max(ans,j++ -i);
          }
       }
       return ans;
   }
};