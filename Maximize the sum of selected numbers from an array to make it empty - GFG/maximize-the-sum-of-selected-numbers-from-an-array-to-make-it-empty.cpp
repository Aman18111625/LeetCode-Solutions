// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  
int maximizeSum(int a[], int n);



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        
        cout << maximizeSum(arr, n) << endl;
        
        
    }

}

// } Driver Code Ends


int maximizeSum(int a[], int n) 
{
    // Complete the function
    map<int,int>mpp;
    int sum=0;
    for(int i=0;i<n;i++) mpp[a[i]]++;
    for(int i=n-1;i>=0;i--)
    {
        if(mpp[a[i]]!=0)
        {
            sum+=a[i];
            mpp[a[i]]--;
            if(mpp[a[i]-1]!=0)
            {
                mpp[a[i]-1]--;
            }
        }
    }
    return sum;
}
