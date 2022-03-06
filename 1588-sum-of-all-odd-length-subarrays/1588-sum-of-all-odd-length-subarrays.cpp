class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            int curr=0,len=0;
            for(int j=i;j<n;j++){
                curr+=arr[j];
                if(len%2==0){
                    sum+=curr;
                }
                len++;
            }
        }
       return sum;
    }
};
