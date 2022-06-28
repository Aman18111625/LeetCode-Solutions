// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Node{
    public:
    int val;
    vector<int>adj;
    Node(int v){
        val=v;
        adj=vector<int>();
    }
};

void dfsTopo(int idx, vector<int>&visited, vector<Node*>&alpha ,string&ans){
    visited[idx]=1;
    for(auto i: alpha[idx]->adj){
        if(!visited[i]){
            dfsTopo(i,visited,alpha,ans);
        }
    }
    ans+=(char)('a'+idx);
}

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<Node*>alpha;
        for(int i=0;i<26;i++){
            Node* n=new Node(i);
            alpha.push_back(n);
        }
        
        for(int i=1;i<N;i++){
            int j=0;
            int t=min(dict[i-1].size(),dict[i].size());
            while(j<t&&dict[i-1][j]==dict[i][j]) j++;
                
            if(j<t){
                (alpha[dict[i-1][j]-'a']->adj ).push_back(dict[i][j]-'a');
            }
        }
        
        string ans="";
        vector<int>visited(26,0);
        for(int i=0;i<26;i++)
            if(!visited[i])
                dfsTopo(i,visited,alpha,ans);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends