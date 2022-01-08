// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
    void helper(int n,vector<int>&res,int num){
        if(n==1){
            res.push_back(num);
            return;
        }
        for(int i=(num%10)+1;i<=9;i++){
            helper(n-1,res,num*10+i);
        }
    }
public:
    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        if(N==1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        
        vector<int>res;
        for(int i=1;i<=10-N;i++){
            helper(N,res,i);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends