//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
        // Code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.count(target)==0) return 0;//if start is not in st then it's not possible
        int ans=1;
        queue<pair<string,int>>q;//{key:value}=>{string,len}
        q.push({start,ans});
        st.erase(start);
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            string s=temp.first;
            int len=temp.second;
            if(s==target) return len;
            for(int i=0;i<s.size();i++){
                char curr=s[i];
                //change every char and find shortest len to reach target
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        q.push({s,len+1});
                        st.erase(s);
                    }
                }
                s[i]=curr;//backtrack
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends