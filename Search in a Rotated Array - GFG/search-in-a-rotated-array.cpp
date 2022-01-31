// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
int getPivot(int arr[],int n){
   int s=0;
   int e=n-1;
   int mid = s+(e-s)/2;

    while (s<e)
    {
       if (arr[mid]>=arr[0])
       {
          s=mid+1;
       }
       else{
           e=mid;
       } 
       mid = s+(e-s)/2;
    }
    return s;
}

int binarySearch(int A[],int l,int h,int key){
   int start = l;
   int end = h;

 int mid = (start+end)/2;
 while(start<=end){
     if(A[mid]==key){
         return mid;
     }
     if(key>A[mid]){
         start=mid+1;
     }
     else{
        end = mid-1;
     }
     mid=(start+end)/2;

 }
 return -1;
}
    public:
    int search(int arr[], int l, int h, int key){
    //complete the function here
      int pivotIdx=getPivot(arr,h);
      if(key>=arr[pivotIdx] && key<arr[h-1])
       return binarySearch(arr,pivotIdx,h-1,key);
      return binarySearch(arr,0,pivotIdx-1,key);
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends