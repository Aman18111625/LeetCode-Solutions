class Solution {
public:
    /*
     Brute force :TC:=>O(N^2) SC:=>O(k)
    void GetMax(vector < int >&nums, int l, int r, vector < int > & arr) {
    int i, maxi = INT_MIN;
    for (i = l; i <= r; i++)
    maxi = max(maxi, nums[i]);
    arr.push_back(maxi);
  }
 vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  int left = 0, right = 0;
  int i, j;
  vector < int > arr;
  while (right < k - 1) {
    right++;
  }
  while (right < nums.size()) {
    GetMax(nums, left, right, arr);
    left++;
    right++;
  }
  return arr;
 }*/
    //TC:=>O(N) SC:=>O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     vector<int>ans;
      deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          if(!dq.empty() and dq.front()==i-k) dq.pop_front();
            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};