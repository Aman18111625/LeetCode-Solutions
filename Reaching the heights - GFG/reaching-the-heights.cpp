// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
   sort(a,a+n);
   vector<int> ans(n);
   int j=0;
   for(int i=1;i<n;i+=2){
       ans[i]=a[j++];
   }
   int size = (n%2==0)?(n-2):(n-1);
   for(int i=size;i>=0;i-=2){
       ans[i] = a[j++];
   }
   int sum=0;
   for(int i=0;i<n;i++){
       if(i%2==0)
       sum+=ans[i];
       else
       sum-=ans[i];
   }
   if(sum ==0){
       vector<int> v={-1};
       // v.push_back(-1);
       return v;
   }
   else
   return ans;
}
