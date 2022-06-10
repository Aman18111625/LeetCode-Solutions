class Solution {
public:
    //Brute-Force Approach:-> By Linear Search->run a for loop and find min element
    //TC:=>O(N)
    //SC:=>O(1)
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto num : nums) ans=min(ans,num);
        return ans;
    }
};