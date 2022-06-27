// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
       //Your code here
      if(num1=="0" or num2=="0") return "0";
        string res = "";
      if(num1[0]=='-' && num2[0]=='-')
      {
          num1=num1.substr(1);
          num2=num2.substr(1);
      }
      else if(num1[0]=='-' && num2[0]!='-')
      {
          num1=num1.substr(1);
          res.push_back('-');
      }
      else if(num1[0]!='-' && num2[0]=='-')
      {
          num2=num2.substr(1);
          res.push_back('-');
      }
       vector<int> num(num1.size() + num2.size(), 0);
       for (int i = num1.size() - 1; i >= 0; --i) {
           for (int j = num2.size() - 1; j >= 0; --j) {
               num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
               num[i + j] += num[i + j + 1] / 10;
               num[i + j + 1] %= 10;
           }
       }
       int i = 0;
       while (i < num.size() && num[i] == 0) ++i;
       while (i < num.size()) res.push_back(num[i++] + '0');
       return res;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends