class Solution {
public:
    //Simple Brute-Force Approach:->Run two for loop and count for every number 
    //TC:=>O(N^2)
    //SC:=>O(1)
    //result: TLE
    // vector<int> countSmaller(vector<int>& nums) {
    //     vector<int>ans;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //       int count=0;
    //       for(int j=i+1;j<n;j++){
    //         if(nums[j]<nums[i]) count++;
    //       }
    //       ans.push_back(count);
    //     }
    //   return ans;
    // }
    
    vector<int>ans;
    
    void merge(vector<int>&nums,int low,int mid,int high,vector<int>&temp,vector<int>&index){
        
       int i = low, j = mid + 1, k = low; int count = 0; 
       while (i <= mid) {
            while (j <= high && nums[index[j]] < nums[index[i]]) {
                count++;
                temp[k++] = index[j++];
            } 
            ans[index[i]] += count;
            temp[k++] = index[i++];
        }
        
        while (j <= high) temp[k++] = index[j++];
        
        for (i = low; i <= high; i++) index[i] = temp[i];
    }
  
  
    void mergeSort(vector<int>&nums,int low,int high,vector<int>&temp,vector<int>&index){
        if(low>=high) return ;
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid,temp,index);
        mergeSort(nums,mid+1,high,temp,index);
        merge(nums,low,mid,high,temp,index);
    }  
  
  
  
     vector<int> countSmaller(vector<int>& nums){
       int n=nums.size();
       ans.resize(n);
       int low=0,high=n-1;
       vector<int>temp(n,0),index;
       for(int i=0;i<n;i++) index.push_back(i);
       mergeSort(nums,low,high,temp,index);
       return ans;
     }
};