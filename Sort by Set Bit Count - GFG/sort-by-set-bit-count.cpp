// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    int countSetBit(int num)
    {
        if(num==0) return 0;
        int cnt=0;
        while(num)
        {
            if(num&1) cnt++;
            num>>=1;
        }
        return cnt;
    }
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        map<pair<int,int>,int,greater<pair<int,int>>>m;
        int val=0;
        for(int i=0;i<n;i++)
        {
            val=countSetBit(arr[i]);
            m[{val,n-i}]=arr[i];
        }
        int j=0;
        for(auto & it : m)
        {
            arr[j++]=it.second;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends