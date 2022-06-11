class Solution {
public:
//Brute-Force Approach:=> Hash map, prefix sum, two sum
//Idea:  create hash map satisfy mapLeft[prefix sum] = i, i is last index in prefix sum
//brute force from last index in array to first index and create suffix sum, find i satisfy mapLeft[x - suffix sum] > 0 
//that's mean prefix sum + suffix sum = x,  and min operation = min (min operation, size(prefix sum) + size(suffix sum) );
//TC: O(n)
//SC: O(n)
// 	int minOperations(vector<int>& nums, int x) {
// 		unordered_map<int, int> mapLeft;
// 		int n = nums.size();
// 		int ans = INT_MAX;

// 		for(int i = 0, prefixSum = 0; i < n; i++) {
// 			prefixSum += nums[i];
// 			mapLeft[prefixSum] = i + 1;
// 			if (prefixSum == x)
// 				ans = min(ans, i + 1);
// 		}

// 		for(int i = n - 1, suffixSum = 0; i >= 0; i--) {
// 			suffixSum += nums[i];
// 			if(suffixSum == x)
// 				ans = min(ans, n - i);
// 			if(mapLeft[x - suffixSum] > 0 && i + 1 > mapLeft[x - suffixSum]) // if i + 1 <= mapLeft => both prefix sum and suffix sum have same elements
// 				ans = min(ans, n - i + mapLeft[x - suffixSum]); // n - i is size suffix sum, mapLeft[x - suffixSum] is size prefix sum
// 		}
// 		return ans == INT_MAX ? -1 : ans;
// 	}
  
  
  //Optimal Approach
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