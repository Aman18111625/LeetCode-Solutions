//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long leftMax[n]={0};
        long long rightMax[n]={0};
        //find leftMax for each index
        leftMax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max((long long)arr[i],leftMax[i-1]);
        }
        //find rightMax for each index
        rightMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max((long long)arr[i],rightMax[i+1]);
        }
        //rain water is difference between min(leftMax[i],rightMax[i])-arr[i] 
        long long res=0;
        for(int i=0;i<n-1;i++){
            res+=(min(leftMax[i],rightMax[i])-arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends