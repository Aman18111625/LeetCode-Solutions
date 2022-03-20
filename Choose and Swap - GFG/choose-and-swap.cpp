// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        if(a.length()==1) return a;
        set<char>st;
        int n=a.length();
        for(int i=0;i<n;i++) st.insert(a[i]);//insert all the character into set
        for(int i=0;i<n;i++){
           st.erase(a[i]);
           if(st.empty()) break;
            char ch=*st.begin();
            if(ch<a[i])
            {
                char ch2=a[i];
                for(int j=0;j<n;j++)
                {
                    if(a[j]==ch2) a[j]=ch;
                    else if(a[j]==ch) a[j]=ch2;
                }
                break;
            }
        }
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends