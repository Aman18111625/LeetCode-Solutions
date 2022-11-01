//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string begin, string end, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.count(end)==0) return ans; 
        queue<vector<string>>q;
        q.push({begin});
        st.erase(begin);
        vector<string>used;
        used.push_back(begin);
        int level=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            //remove words from prev level
            if(temp.size()>level){
                level++;
                for(auto &it : used){
                    st.erase(it);
                }
            }
            string word=temp.back();
            if(word==end){
                if(ans.size()==0) ans.push_back(temp);
                else if(ans[0].size()==temp.size()) ans.push_back(temp);
            }
            for(int i=0;i<word.size();i++){
                char curr=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                       temp.push_back(word);
                       q.push(temp);
                       used.push_back(word);
                       temp.pop_back();
                    }
                }
                word[i]=curr;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends