class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int i;
        for(i=1;i<n;i++)
        {
          if(arr[i]>arr[i-1]) continue;
          else  break;
        }
       if(i==n or i==1) return false;
       for(;i<n;i++)
       {
         if(arr[i-1]>arr[i]) continue;
         else return false;
       }
       if(i==n) return true;
      return false;
    }
};