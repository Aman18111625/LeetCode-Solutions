// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	    //step1 transpose it
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            int temp=arr[i][j];
	            arr[i][j]=arr[j][i];
	            arr[j][i]=temp;
	        }
	    }
	    //step-2 reverse it
	    for(int i=0;i<n;i++)
	    {
	       int left=0,right=n-1;
	       while(left<right)
	       {
	           int temp=arr[left][i];
	           arr[left][i]=arr[right][i];
	           arr[right][i]=temp;
	           left++;
	           right--;
	       }
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends