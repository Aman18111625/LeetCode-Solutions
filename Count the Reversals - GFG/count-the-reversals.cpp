// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n=s.size();
    if(n&1) return -1;
    int count=0;
    stack<char>st;
    for(int i=0;i<n;i++){
        //if opening bracket then simply push
        if(s[i]=='{') st.push(s[i]);
        else {//now closing bracket
            if(st.empty()){//if stack is empty then convert closing into opening
                s[i]='{';
                st.push(s[i]);
                count++;
            }else st.pop();
        }
    }
    return st.size()/2+count;
}