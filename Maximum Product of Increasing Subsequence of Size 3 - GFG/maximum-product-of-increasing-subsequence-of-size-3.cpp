// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        set<long int>st;
        vector<int>maxi(n),ans;
        long int curr=0,res=-1;
        maxi[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) 
        {
            maxi[i]=max(maxi[i+1],arr[i]);
        }
        st.insert(arr[0]);
          int elem;
        for(int i=1;i<n;i++){
            st.insert(arr[i]);
            auto it=st.find(arr[i]);
            if(it!=st.begin()) {
                it--;
                elem=*it;
                if(arr[i]<maxi[i]){
                    curr=(long )arr[i]*maxi[i]*elem;
                    if(curr>res){
                        ans={elem,arr[i],maxi[i]};
                        res=curr;
                    }
                }
            }
        }
        if(ans.empty()) return {-1};
        return ans;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends