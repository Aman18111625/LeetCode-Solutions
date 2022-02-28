class Solution {
public:
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
    }
};