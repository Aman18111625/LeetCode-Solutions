class Solution {
public:
  //Brute Force Approach
  //TC:=>O(N^2)
  //SC:=>O(N)
  //Check for every envelope ->in how many envelopes this can fit
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     int n=envelopes.size();
    //     if (n==0) return 0;
    //     sort(envelopes.begin(),envelopes.end());
    //     vector<int>dp(n, 1);
    //     for (int i = 0; i < n; ++i)
    //         for (int j = 0; j < i; ++j)
    //             if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
    //                 dp[i]  = max(dp[i] , dp[j] + 1);
    //     return *max_element(dp.begin(), dp.end());
    // }
 static bool func(vector<int>& e1, vector<int>& e2){
         return (e1[0]==e2[0])?e1[1]>e2[1]:e1[0]<e2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),func);
        vector<int> v;
        for(int i=0;i<envelopes.size();i++)
        {
            if(i==0 || envelopes[i][1]>v[v.size()-1])
               {
                   v.push_back(envelopes[i][1]);
               }
               else
               {
                   int index=binarysearch(v,envelopes[i][1]);
                   v[index]=envelopes[i][1];
               }
        }
     return v.size();           
    }
    
    int binarysearch(vector<int> &v,int x)
    {
        int i=0;
        int j=v.size()-1;
        int ans=0;
        while(i<=j)
        {
            int mid=(i+(j-i)/2);
            if(v[mid]==x)
                return mid;
            else if(v[mid]>x)
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};