// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[N],indegree(N,0);
	    //create graph
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].second].push_back(pre[i].first);
	        indegree[pre[i].first]++;
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    int ans=0;
	    while(!q.empty()){
	        int temp=q.front(); q.pop();
	        ans++;
	        for(auto it : adj[temp]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return ans==N;//if ans ==N then there's no cycle so it's possible else not possible
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends