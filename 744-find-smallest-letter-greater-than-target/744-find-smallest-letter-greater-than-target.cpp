class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //Brute-Force Approach->TC:=>O(N),SC:=>O(1)
        // for(auto &ch : letters){
        //   if(ch>target) return ch;
        // }
        // return letters[0];
      //Optimized Using Binary Search ->TC:=>O(logN),SC:=>O(1)
      int mid, low = 0, high = letters.size() - 1;
	      	while(low <= high){
			     mid = (low + high) / 2;
			     if(letters[mid] <= target){
			     	low = mid + 1;
			     }
			     else{
				    high = mid-1;
			     }
	  	 }
		    if(letters[low] > target){
			    return letters[low];
		    }
		   return letters[0];
     }
};