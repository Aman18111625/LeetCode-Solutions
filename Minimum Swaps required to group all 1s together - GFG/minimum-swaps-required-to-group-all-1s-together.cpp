// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    // Complete the function
    int len=0;
    for(int i=0;i<n;i++) len+=arr[i];
    if(len==0) return -1;//all are zeroes
    int curr=0,start=0,end=len-1,maxOnes=0;
    for(int i=0;i<len;i++) curr+=arr[i];
    while(end<n){
        maxOnes=max(maxOnes,curr);
        if(end+1<n) curr+=arr[end+1];
        curr-=arr[start++];
        end++;
    }
    return len-maxOnes;
}