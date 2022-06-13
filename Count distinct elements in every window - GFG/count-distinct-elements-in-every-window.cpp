// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here
        unordered_map<int,int>mpp;
        vector<int>res;
        int i=0,j=0;
        for(;i<k;i++) mpp[arr[i]]++;
        res.push_back(mpp.size());
        while(i<n)
        {
            mpp[arr[i]]++;
            mpp[arr[j]]--;
            if(mpp[arr[j]]==0) mpp.erase(arr[j]);
            res.push_back(mpp.size());
            j++;
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends