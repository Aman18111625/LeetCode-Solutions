// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    struct compare
	{
	    bool operator() (const pair<long double, long long> &p1, const pair<long double, long long> &p2)
	    {
	        return (p1.first/p1.second)>(p2.first/p2.second);
	    }
	};
	
	bool isPerfectSq(long long num)
	{
	    long long x = sqrt(num);
	    return (x*x==num);
	}
	
    
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	     vector<pair<long double, long long>> gold(N);
	    
	    for(int i=0 ; i<N ; i++)
	    {
	        gold[i] = {p[i], w[i]};
	    }
	    
	    sort(gold.begin(), gold.end(), compare());
	    
	    long double ans=0;
	    
	    for(int i=0 ; i<N && C>0 ; i++)
	    {
	        if(isPerfectSq(gold[i].second))
	        {
	            continue;
	        }
	        
	        if(C>=gold[i].second)
	        {
	            ans += gold[i].first;
	            C -= gold[i].second;
	        }
	        else
	        {
	            ans += (gold[i].first/gold[i].second)*C;
	            C=0;
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends