// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         int ptr[K]={ };
         for(int i=0;i<K;i++)
          pq.push({arr[i][0],i});
          
          vector<int>ans;
          while(!pq.empty()){
             auto p=pq.top();
             ans.push_back(p.first);
             int row=p.second;
             ptr[row]++;
             if(ptr[row]<K)
             {
                 pq.push({arr[row][ptr[row]],row});
             }
             pq.pop();
          }
          return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends