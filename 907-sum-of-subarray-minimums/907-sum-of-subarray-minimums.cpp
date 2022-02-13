class Solution {
public:
  /*
  //Brute Force : Generate all the subarrays and find minimum of each subarray and add in answer 
  //TC:=>O(N^2)
  //SC:=>O(1)
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++)
        {
          int mini=INT_MAX;
          for(int j=i;j<n;j++)
          {
              mini=min(mini,arr[j]);
              sum=(sum+mini)%mod;
          }
        }
      return sum;
    }
    */
  //Optimal Approach: 
//Calculate next smaller to left and right and count number of times a[i] is the min
  //TC:=>O(N)
  //SC:=>O(N)+O(N)
  int sumSubarrayMins(vector<int>&arr) {
       int n=arr.size();
       vector<int>left(n,-1),right(n,n);//store index of smaller element to the left and right 
       stack<int>st;
       for(int i=0;i<n;i++)
       {
         if(st.empty()) left[i]=-1;
         while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
         if(st.empty()) left[i]=-1;
         else left[i]=st.top();
         st.push(i);
       }
       st=stack<int>();
       for(int i=n-1;i>=0;i--)
       {
         if(st.empty()) right[i]=n;
         while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
         if(st.empty()) right[i]= n;
         else right[i]=st.top();
         st.push(i);
       }
      int sum=0;
      long mod= 1e9+7;
       for(int i=0;i<n;i++)
       {
         int countLeft=i-(left[i]+1)+1;
         int countRight=(right[i]-1)-i+1;
         sum=(sum+(long)arr[i]*countLeft*countRight)%mod;
       }
    return sum;
    }
};
      
       