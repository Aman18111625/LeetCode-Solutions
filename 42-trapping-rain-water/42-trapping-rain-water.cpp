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
      // int trap(vector<int>& height) {
      //   int n=height.size();
      //   vector<int>leftMax(n),rightMax(n);
      //   leftMax[0]=height[0];
      //   for(int i=1;i<n;i++){
      //     leftMax[i]=max(leftMax[i-1],height[i]);
      //   }
      //   rightMax[n-1]=height[n-1];
      //   for(int i=n-2;i>=0;i--){
      //     rightMax[i]=max(rightMax[i+1],height[i]);
      //   }
      //   int ans=0;
      //   for(int i=0;i<n;i++){
      //     ans+=min(leftMax[i],rightMax[i])-height[i];
      //   }
      //   return ans;
      // }
       
        //Optimal Approach ->Using Two Pointer
       //TC:=>O(N)
      //SC:=>O(1)
      //Intution:->We need a minimum of leftMax and rightMax.So if we take the case when height[l]<=height[r] we increase l++, so we can surely say that there is a block with height more than height[l] to the right of l. And for the same reason when height[r]<=height[l] we can surely say that there is a block to the left of r which is at least of height height[r]. So by traversing with these cases and using two pointers approach the time complexity can be decreased without using extra space.
        int trap(vector<int>&arr){
          int n=arr.size();
          int left=0,right=n-1;
          int leftMax=0,rightMax=0;
          int ans=0;
          while(left<right){
            if(arr[left]<=arr[right]){
                if(leftMax<=arr[left]) leftMax=arr[left];
                else ans+=(leftMax-arr[left]);
                left++;
            }else{
                if(arr[right]>=rightMax) rightMax=arr[right];
               else ans+=(rightMax-arr[right]);
                right--;
            }
          }
          return ans;
        }
  
};