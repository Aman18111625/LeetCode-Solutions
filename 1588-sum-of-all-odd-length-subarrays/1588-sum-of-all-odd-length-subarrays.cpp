class Solution {
public:
  //Approach-1 generate all the sub-array & check for every odd length subarray
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            int curr=0,len=1;
            for(int j=i;j<n;j++){
                curr+=arr[j];
                if(len&1){
                    sum+=curr;
                }
                len++;
            }
        }
       return sum;
    }
};
