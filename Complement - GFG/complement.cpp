//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int currCnt = 0;
        int ans = 0;
        int currLowIndex = -1;
        int ansLowIndex = -1;
        int ansHighIndex = -1;
        bool isFirst = true;
        for(int i = 0; i < n; i++){
            if(str[i] == '0'){
                currCnt++;
                if(isFirst || currCnt < 1){
                    currCnt = 1;
                    currLowIndex = i;
                    isFirst = false;
                }
                if(currCnt > ans){
                    ansLowIndex = currLowIndex + 1;
                    ansHighIndex = i + 1;
                    ans = currCnt;
                }
            }
            else{
                currCnt--;
            }
        }
        vector<int> res;
        if(currLowIndex == -1){
            res.push_back(-1);
            return res;
        }
        else{
            res.push_back(ansLowIndex);
            res.push_back(ansHighIndex);
            return res;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends