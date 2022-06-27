// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long>pq;
        for(int i=0;i<K2;i++) pq.push(A[i]);
        for(int i=K2;i<N;i++){
            long long temp=pq.top();
            if(A[i]<temp) {
                pq.pop();
                pq.push(A[i]);
            }
        }
        pq.pop();//k2 smallest element out
        long long ans=0;
        while(pq.size()>K1){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends