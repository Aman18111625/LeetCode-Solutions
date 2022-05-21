class Solution {
public:
  //Brute Force:->TLE
  //TC:->O(N^2)
  //SC:->O(1)
    // int reversePairs(vector<int>& arr) {
    //     int Pairs = 0;
    //     for (int i = 0; i < arr.size(); i++) {
    //     for (int j = i + 1; j < arr.size(); j++) {
    //       if ((long long int)arr[i] >(long long int) 2*arr[j]) Pairs++;
    //      }
    //     }
    //   return Pairs;
    // }
  //Optimal Approach->Using Merge Sort
  //it's kind of count inversion problem but here we have to check arr[i]<=2*arr[j]
    int merge(vector<int>&nums,int low,int mid,int high){
      int total=0;
      int j=mid+1;
      for(int i=low;i<=mid;i++){
        while(j<=high && nums[i]>2LL*nums[j]){
          j++;
        }
        total+=(j-(mid+1));
      }
      vector<int>temp;
      int left=low,right=mid+1;
      while(left<=mid && right<=high){
          if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
          }else{
            temp.push_back(nums[right++]);
          }
      }
      
      while(left<=mid){
        temp.push_back(nums[left++]);
      }
      
      while(right<=high){
        temp.push_back(nums[right++]);
      }
      
      for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
      }
      return total;
    }
  
    int mergeSort(vector<int>&arr,int low,int high){
      if(low>=high) return 0;
      int mid=(low+high)/2;
      int inv=mergeSort(arr,low,mid);
      inv+=mergeSort(arr,mid+1,high);
      inv+=merge(arr,low,mid,high);
      return inv;
    }
  
    
    int reversePairs(vector<int>& arr){
       return mergeSort(arr,0,arr.size()-1);
    }
};
 