// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
       // int lo=low,hi=high;
       if(low>high) return arr[0];
       int mid=(low+high+1)>>1;
       if(arr[mid]<arr[mid-1]) return arr[mid];
       else if(arr[mid]>arr[0]) return minNumber(arr,mid+1,high);
       else return minNumber(arr,low,mid-1);
    }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends