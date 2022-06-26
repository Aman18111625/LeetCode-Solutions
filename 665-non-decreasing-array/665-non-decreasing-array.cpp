class Solution {
public:
    // bool checkPossibility(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return true;
    //    int count = 0, mini = INT_MIN;
    //     for(int i = 0; i < n-1; i++){
    //         if(nums[i] <= nums[i+1]){
    //             mini = nums[i];
    //         }
    //         else{
    //             if(nums[i+1] < mini)nums[i+1] = nums[i];
    //             count++;
    //             if(count > 1)return false;
    //         }
    //     }
    //     return true;
    // }
      bool checkPossibility(vector<int>& nums) {
        bool is_modified = false;
        for (int i = 1, prev = nums[0]; i < nums.size(); i++) {
            if (nums[i] < prev) {
                if (is_modified) return false;
                is_modified = true;
                if (i - 2 >= 0 && nums[i-2] > nums[i]) continue;
                
            }
            prev = nums[i];
        }
        return true;
     }

};