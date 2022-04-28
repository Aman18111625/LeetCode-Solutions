// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        sort(candies,candies+N);
        vector<int>res;
        int min=0;
        int n=N;
        for(int i=0;i<n;i++){
            min+=candies[i];
            n-=k;
        }
        res.push_back(min);
        int max=0;
        n=N;
        int t=0;
        for(int i=n-1;i>=t;i--){
            max+=candies[i];
            t+=k;
        }
        res.push_back(max);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends