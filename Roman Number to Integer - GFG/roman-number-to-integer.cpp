//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
       int sum=0;
       for(auto ch: str){
           if(ch=='M') sum+=1000;
           else if(ch=='D') sum+=500;
           else if(ch=='C') sum+=100;
           else if(ch=='L') sum+=50;
           else if(ch=='X') sum+=10;
           else if(ch=='V') sum+=5;
           else if(ch=='I') sum+=1;
       }
       
        if(str.find("IV") != -1) sum -= 2;
        if(str.find("IX") != -1) sum -= 2;
        if(str.find("XL") != -1) sum -= 20;
        if(str.find("XC") != -1) sum -= 20;
        if(str.find("CD") != -1) sum -= 200;
        if(str.find("CM") != -1) sum -= 200;

        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends