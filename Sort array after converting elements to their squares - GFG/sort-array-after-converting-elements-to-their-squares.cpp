// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution
{
   public:
    vector<int> sortSquares(int A[], int arr_size)
    {
    	//Write your code here
    	for(int i=0;i<arr_size;i++){
    	    A[i]*=A[i];
    	}
    	sort(A,A+arr_size);
    	vector<int>ans;
    	for(int i=0;i<arr_size;i++) ans.push_back(A[i]);
    	return ans;
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    vector<int> ans=ob.sortSquares(arr, n);
	    for(auto it : ans){
    	    cout<<it<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends