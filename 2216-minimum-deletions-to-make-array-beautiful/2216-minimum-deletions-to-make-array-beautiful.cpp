class Solution {
public:
  //Approach-1 : Using Stack
  //TC:=>O(N)
  //SC:=>O(N)
    // int minDeletion(vector<int>& nums) {
    //     int n=nums.size();
    //     stack<int>st;
    //     int ind=-1,count=0;
    //     for(int i=0;i<n;i++){
    //     //if stack is not empty() && for even ind if nums[i]==st.top() then we need to delete it.
    //      if(!st.empty() &&  nums[i]==st.top() && ind%2==0){
    //          count++; 
    //      }else{//odd ind,so simply push
    //        ind++;
    //        st.push(nums[i]);
    //      }
    //     }
    //     if(ind%2==0) count++;//for last ind
    //     return count;
    // }
  
  
  //Optimized Approach:=>Using Two Pointer
  //TC:=>O(N)
  //SC:=>O(1)
    int minDeletion(vector<int>&nums){
      int n=nums.size();
      int count=0,i;
      for(i=0;i<n-1;i++){
        int curr_ind=i-count;//since index is change after every deletion
        if( curr_ind%2==0 && nums[i+1]==nums[i]) count++;//if curr_ind is even
      }
      if((i-count)%2==0) count++;
      return count;
    }
};

/*


Using two pointer .. O(1) space:

class Solution{
public:
int minDeletion(vector<int>&a){
int n=a.size();
int count=0;
for(int i=0;i<n-1;i++){
		int index=i-count;
	//  since the index keeps changing after every deletion 
		if(a[i+1]==a[i] && index%2==0)
			count++;
}
		if((n-count)%2!=0)
			count++;
		return count;
	}
*/