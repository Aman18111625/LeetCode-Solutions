//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size(), m = heights[0].size();
        
        vector<vector<int>> diff(n, vector<int> (m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        diff[0][0] = 0;
        
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        
        while(!pq.empty()){
            
            int dif = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == n-1 and y == m-1){
                return dif;
            }
            
            for(int i=0; i<4; i++){
                
                int newx = x + delrow[i];
                int newy = y + delcol[i];
                
                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    
                    int neweffort = max(abs(heights[x][y] - heights[newx][newy]), dif);
                    
                    if(neweffort < diff[newx][newy]){
                        diff[newx][newy] = neweffort;
                        pq.push({neweffort, {newx, newy}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends