class Solution {
public:
  /*
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string>ans;
         int n=nums.size();
         if(n==0) return ans;
         if(n==1) return {to_string(nums[0])};
         string temp="";
         int j=0;
         for(int i=1;i<=n;i++){
           if(i<n && nums[i]-1==nums[i-1]) continue;
           else if(j==i-1) ans.push_back(to_string(nums[j]));
           else{
             temp+=to_string(nums[j]);
             temp+="->";
             temp+=to_string(nums[i-1]);
             ans.push_back(temp);
             temp="";
           }
           j=i;
         }
      return ans;
    }*/
  vector<string> summaryRanges(vector<int>&nums){
        int n=nums.size();
        vector<string>ans;
        if(n==0) return ans;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                end = nums[i];
            }
            else {
                if (start == end) {
                    ans.push_back(to_string(end));
                }
                else {
                    ans.push_back(to_string(start) + "->" + to_string(end));                 
                }
                start = nums[i];
                end = nums[i];
            }
        }
       //checking for last range  
        if (start == end) {
            ans.push_back(to_string(end));
        }
        else {
            ans.push_back(to_string(start) + "->" + to_string(end));             
        }
        return ans;
  }
};