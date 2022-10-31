//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
           vector<int> ans(4,-1);

        map<int, pair<int, int>> mp;

        bool flag = false;

        int sum = 0;

        for(int i=0;i<N;i++)

        {

            for(int j=i+1;j<N;j++)

            {    sum = A[i]+A[j];

                if(mp.find(sum)!=mp.end())

                {

                    auto pr =  mp[sum];

                    int l = pr.first;

                    int m = pr.second;

                    if(i==m || i==l)continue;

                    if(j==l || j==m) continue;

                    if(!flag)

                    {

                    ans[0] = l;

                    ans[1] = m;

                    ans[2] = i;

                    ans[3] = j;

                    }

                    else

                    {

                        if(flag)

                        {

                            if(ans[0]>l)

                            {

                                ans[0] = l;

                                ans[1] = m;

                                ans[2] = i;

                                ans[3] = j;

                            }

                            else

                            {

                                if(ans[0]==l)

                                {

                                    if(ans[1]>m)

                                    {

                                          ans[1] = m;

                                          ans[2] = i;

                                          ans[3] = j;

                                    }

                                    else

                                    {

                                        if(ans[1] == m)

                                        {

                                           if(ans[2]>i)

                                           {

                                                ans[2] = i;

                                               ans[3] = j;

                                           }

                                           else

                                           {

                                               if(ans[2]==i)

                                               {

                                                   if(ans[3]>j)

                                                   {

                                                       ans[3] = j;

                                                   }

                                               }

                                           }

                                        }

                                    }

                                }

                            }

                        }

                    }

                    flag = true;

                }

                pair<int, int> pr;

                pr = {i,j};

                mp[sum] = pr;

                

            }

        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends