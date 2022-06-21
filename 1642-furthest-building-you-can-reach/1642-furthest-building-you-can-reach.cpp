class Solution {
public:
  /*
  Thought-Process:=>Ladders can be used anywhere even for an infinite jump to next building. We need to realise that bricks limit our jumping capacity if used at wrong jumps. So, bricks should be used only on the smallest jumps in the path and ladders should be used on the larger ones.
  
We could have sorted the jumps and used ladders on largest L jumps(where, L is number of ladders) and bricks elsewhere. But, we don't know how many jumps will be performed or what's the order of jump sequence.

For this, we will assume that the first L jumps are the largest ones and store the jump heights in ascending order. We can use priority_queue / min-heap for this purpose (since we would be needing to insert and delete elements from it...explained further).

Now, for any further jumps, we need to use bricks since the first L jumps have used up all the ladders. Let's call the jump height requried from now on as curJumpHeight. Now,

1. If curJumpHeight > min-heap top : We have the choice to use bricks on the previous jump which had less jump height. So, we will use that many bricks on previous (smaller) jump and use ladder for current (larger) jump.

2. If curJumpHeight <= min-heap top : There's no way to minimize usage of bricks for current jump. We need to spend atleast curJumpHeight number of bricks
  */
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0,size=heights.size();
        //min heap
       priority_queue<int,vector<int>,greater<int>>pq;
//first ladder number of jumps would be assumed to be the largest hence, push all these jumps into the pq
      while(i<size-1 && pq.size()<ladders){
        int jumpHeight=heights[i+1]-heights[i];
        if(jumpHeight>0) pq.push(jumpHeight);
        i++;
      }
      
      //from here ,we  can't use ladder and need to spend bricks from now
      while(i<size-1){
      int jumpHeight=heights[i+1]-heights[i];
      if(jumpHeight>0){
//First check if we have a previous jump requiring less number of bricks than currentDiff
			if(!pq.empty() && pq.top() < jumpHeight) {                    
				// if there is, just use bricks for that jump and assign ladder for current one
				bricks -= pq.top(); pq.pop(); 
				pq.push(jumpHeight);                    
			}
	 //jumpHeight is already minimum jump size. So, no choice than spending that many bricks
			else bricks -= jumpHeight;
      }
      if(bricks<0) return i;//bricks become negative,so we can't travel any more as all bricks and ladders are used till now.
      i++;
    }
    return i;
  }
};

