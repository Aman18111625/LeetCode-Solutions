// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans="";
  int cnt=1,n=src.size();
  for(int i=0;i<n;i++){
      if(src[i]==src[i+1]){
         cnt++; 
      }else{
          ans+=src[i];
          ans+=to_string(cnt);
          cnt=1;
      }
  }
  return ans;
}     
 
