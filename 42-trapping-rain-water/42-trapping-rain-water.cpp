class Solution {
public:
     //Brute-Force Approach
     //TC:=>O(N^2)
     //SC:=>O(1)
     //We know that we have to check for every index how many water can be stored at this index. So we'll simply find leftmax and rightmax for every index and we know that
  //water stored=min(leftMax,rightMax)-arr[i];
    // int trap(vector<int>& height) {
    //     int ans=0;
    //     int n=height.size();
    //     for(int i=0;i<n;i++){
    //       int j=i;
    //       int leftMax=0,rightMax=0;
    //       while(j>=0){
    //         leftMax=max(leftMax,height[j]);
    //         j--;
    //       }
    //       j=i;
    //       while(j<n){
    //         rightMax=max(rightMax,height[j]);
    //         j++;
    //       }
    //       ans+=min(rightMax,leftMax)-height[i];
    //     }
    //     return ans;
    // }
      //Better Approach->Instead of find leftMax and rightMax everytime we can pre-compute them 
  //TC:=>O(N)
  //SC:=>O(N)
      int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n),rightMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
          leftMax[i]=max(leftMax[i-1],height[i]);
        }
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
          rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
          ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
      }
};