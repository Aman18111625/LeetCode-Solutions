// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int sum=INT_MIN,difference=INT_MAX,n=arr.size();
        for(int i=0;i<n-1;i++){
            int low=i+1;
            int high=n-1;
            while(low<high){
                int diff=abs(target-arr[i]-arr[low]-arr[high]);
                if(diff==difference){
                    if(sum<arr[i]+arr[low]+arr[high]){
                        sum=arr[i]+arr[low]+arr[high];
                    }
                }else if(difference>diff){
                    difference=diff;
                    sum=arr[i]+arr[low]+arr[high];
                }
                if(diff==0) return target;
                else if(target>arr[i]+arr[low]+arr[high]) low++;
                else high--;
            }
        }
        return sum;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends