class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        if(n==2) return 1;
        int idx1=-1,i=0,maxi=INT_MIN;
        for(;i<n;i++)
        {
            if(seats[i]==1)
            {
                if(idx1==-1) maxi=i;
                else maxi=max(maxi,(i-idx1)/2);
                idx1=i;
            }
        }
        if(seats[n-1]==0) maxi=max(maxi,n-idx1-1);
        return maxi;
    }
};
