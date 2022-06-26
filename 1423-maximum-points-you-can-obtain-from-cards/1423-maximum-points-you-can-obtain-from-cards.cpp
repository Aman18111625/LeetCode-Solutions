class Solution {
public:
  //Recursive Solution :=> Got TLE
  //By maintaining two pointers l and r. For each (l, r), we can either take card[l] or card[r]. We will recursively explore both the option and choose the one that leads to maximum score. This process will be repeated till k cards are chosen.
//    int solve(vector<int>& cp, int k, int l, int r) {
// 	  if(k == 0) return 0;
// 	  return max(cp[l] + solve(cp, k - 1, l + 1, r), cp[r] + solve(cp, k - 1, l, r - 1));
//    }
  
//    int maxScore(vector<int>& cp, int k) {
// 	   return solve(cp, k, 0, size(cp) - 1);
//    }

  //Optimized Approach:->In this approach,we will just take the first take first k cards on the left and try to replace them one by one with cards on right end.
//This solution will essentially try out every possible combination of taking k cards from the left and right end of the array. After each replacement from the right, we will only store the maximum of earlier score and score after replacement from the right end.

  //TC:=> O(K)
  //SC:=> O(1)
    int maxScore(vector<int>& nums, int k) {
         int sum=0;
         for(int i=0;i<k;i++) sum+=nums[i];
         int ans=sum;
         int l=k-1,r=nums.size()-1;
         while(l>=0 ){
           ans=max(ans,sum+=(nums[r]-nums[l]));
           l--;
           r--;
         }
        return ans;
    }
};