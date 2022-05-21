class Solution {
public:
// Brute Force Approach:=>
// //Time Complexity: O(N^2) 
// //Space Complexity: O(1)
// Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element as the answer. If not, proceed with the next element in the array and repeat the process.


    // Better Approach->simply store in hashmap and find which one is majority element
    //Time-Complexity:=>O(NlogN) if we'll use freq array then TC:=>O(N)
    //Space-Complexity:=>O(N)
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int>mpp;
    //     for(auto &num: nums) mpp[num]++;
    //     int n=nums.size()/2;
    //     for(auto &it : mpp){
    //       if(it.second>n) return it.first;
    //     }
    //   return -1;
    // }
  //Time-COmplexity:=>O(N)
  //Space-Complexity:=>O(1)
  //Intution:-> Basically we have given that majority element always exits ->that means there is a element which count is >N/2.
  //Now cnt of majority =>N/2+x and cnt of minority => N/2-x;
//   Where x is the number of times it occurs after reaching the minimum value N/2.
// Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 
   int majorityElement(vector<int>& nums) {
        int count=0,candidates=0;
        for(auto &num:nums)
        {
         if(count==0) candidates=num;
         if(num==candidates) count++;
         else count--;
        }
        return candidates;
    }
};