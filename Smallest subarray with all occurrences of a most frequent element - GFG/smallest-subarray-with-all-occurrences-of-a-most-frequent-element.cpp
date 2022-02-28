// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	// Complete the function
    	unordered_map<int,int>mpp;
    	int len=0;
    	for(int i=0;i<n;i++){
    	    mpp[a[i]]++;
    	}
    	for(auto &it:mpp){
    	    len=max(it.second,len);
    	}
    	unordered_map<int,pair<int,int>>ump;
    	for(int i=0;i<n;i++){
    	    if(mpp[a[i]]==len){
    	        if(ump.find(a[i])==ump.end()){
    	            ump[a[i]]={i,i};
    	        }
    	        else{
    	            ump[a[i]].second=i;
    	        }
    	    }
    	}
    	int minD=INT_MAX;
    	unordered_map<int,int>mp;
    	for(auto &it:ump){
    	    mp[it.first]=it.second.second-it.second.first;
    	    minD=min(minD,it.second.second-it.second.first);
    	}
    	vector<int>answer;
    	int l=0, f=0;
    	for(int i=0;i<n;i++){
    	    if(mp[a[i]]==minD){
    	        f=ump[a[i]].first;
    	        l=ump[a[i]].second;
    	        break;
    	    }
    	}
    	for(int i=f;i<=l;i++){
    	    answer.push_back(a[i]);
    	}
    	return answer;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}
  // } Driver Code Ends