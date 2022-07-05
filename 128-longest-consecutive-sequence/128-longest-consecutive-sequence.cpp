class Solution {
public:
  //Brute-Force Approach
  //TC:=>O(NLOGN)
  //SC:=>O(1)
  //sort the given array and now run a for loop two find longest Consecutive Array
    // int longestConsecutive(vector<int>&arr) {
    // if(arr.empty()) return 0;
    // sort(arr.begin(),arr.end());
    // int n=arr.size();
    // int ans=1,prev=arr[0],curr=1;
    // for(int i=1;i<n;i++){
    //     if(arr[i]==prev+1){
    //         curr++;
    //     }else if(arr[i]!=prev){
    //         curr=1;
    //     }
    //     prev=arr[i];
    //     ans=max(ans,curr);
    // }
    // return ans;
    // }
  //Optimal Approach ->Using Hashset
  //TC:=>O(N)
  //SC:=>O(N)
  //We'll first push all are elements in the HashSet. Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence. 
  int longestConsecutive(vector<int>&nums){
     if(nums.empty()) return 0;
     unordered_set<int> set(begin(nums), end(nums));
	   int longest = 0;
	   for(auto& num : set) {
        if(set.count(num - 1)) continue;//if prev available then continue
		    int curr = 1;
		    while(set.count(num + curr)) curr++;
		    longest = max(longest, curr);
	    }
	   return longest;
  }
};

  

   
    