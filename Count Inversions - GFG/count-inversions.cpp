// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    long long int merge(long long arr[],long long temp[],long long low,long long mid,long long high){
       long long  start=low;
       long long  count=0;
       long long j=mid+1,k=low;
       while(  (low<=mid) &&   (j<=high) )
       {
           if(arr[low]<=arr[j])temp[k++]=arr[low++];
           else
           {  count+=  mid+1-low;
              temp[k++]=arr[j++];
           }
       }
       while(low<=mid)temp[k++]=arr[low++];
       while(j<=high)temp[k++]=arr[j++];
       
       for(long long p=start;p<=high;p++)arr[p]=temp[p];
     
     return count;   
    }
    
    long long int mergeSort(long long arr[],long long temp[],long long low,long long high){
        long long  count=0,mid;
         if(low<high){
          mid=(low+high)/2;
          count += mergeSort( arr,temp, low, mid);
          count += mergeSort(arr,temp, mid+1, high);
          count += merge ( arr,temp,low, mid, high);
       }
       return count;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends