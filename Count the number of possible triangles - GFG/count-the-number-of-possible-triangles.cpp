// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //for a traingle sum of any side should be greater than third side
    //Brute-force run three for loop & check condition and count number of possible triangle
    //TC:->O(N^3) && SC:->O(1)
    //Function to count the number of possible triangles.
    //optimal approach
    //1.sort the array
    //2.run a for loop from back & two-pointer approach
    //TC:=>O(N^2)
    //SC:=>O(1)
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int count=0;
        sort(arr,arr+n);
        for(int i=n-1;i>=2;i--){
            int low=0,high=i-1;
            while(low<high){
                if(arr[low]+arr[high]>arr[i]){
                    count+=(high-low);
                    high--;
                }else{
                    low++;
                }
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends