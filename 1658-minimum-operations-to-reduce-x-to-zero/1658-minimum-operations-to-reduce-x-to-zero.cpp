class Solution {
public:
  //so according to the question ->we can remove leftmost or rightmost element and we have to remove such that->
  //1.sum of removed elements is equal to X
  //2.remove in minimum number of operations
  //Now main point is that if we're able to remove all such elements than remaining array is a subarray and sum of all remaining elements =(sum-x);
  //So basically now our task is to find a maximum length subarray whose sum is (sum-x)
  //TC:->O(N)
  //SC:->O(1)
    int minOperations(vector<int>& nums, int x) {
        int sum1=0, n=nums.size();;
        for(auto num : nums) sum1+=num;
        sum1-=x;//sum of remaining elements
        if(sum1==0) return n;//if sum of total elements is equal to x then we have to remove all the elements.
        int maxLength=0,sum2=0;
        //sliding window technique:->i points to begining of subarray and j points to end of subarray 
        for(int i=0,j=0;j<n;j++){
           sum2+=nums[j];
           while(i<n && sum2>sum1) sum2-=nums[i++];
           if(sum1==sum2){//if sum2 is equal to our desired sum which (sum1-x) then take max length 
             maxLength=max(maxLength,j-i+1);  
           }
        }
        if(maxLength==0) return -1;//it's not possible
        return n-maxLength;
    }
};