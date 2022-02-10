class Solution {
public:
  /*
  #define pi pair<int,int>
  //Approach-1 Using Max & Min Heap
  //TC;=>O(N)
  //SC:=>O(N)
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pi,vector<pi>,greater<pi>>second; //max-heap
        priority_queue<pi>first; //min-heap
		
        for(int i=0;i<n;i++)
        {
           second.push({nums[i],i});//push whole array into max-heap
        }
			
			  for(int i=0;i<n;i++){
        first.push({nums[i],i}); // add current element to left part
			// keep popping from right part till you get an element that has index > i
            while(!second.empty() && second.top().second<=i) second.pop(); 
            pi topof2=second.top(); // top element of right part
            pi topof1=first.top(); //top element of left part
			
            if(topof1.first<=topof2.first)
                return i+1;   
        }
        return -1; // if no such answer possible
    }*/
  //Approach-2 Using Left and right array
   int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int left[n],right[n];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        //left->max and right->min
        for(int i=1;i<n;i++)
        {
             left[i]=max(left[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
          right[i]=min(nums[i],right[i+1]);  
        }
        for(int i=0;i<n;i++)
        {
         if(left[i]<=right[i+1]) return i+1;  
        }
        return -1;
    }
};