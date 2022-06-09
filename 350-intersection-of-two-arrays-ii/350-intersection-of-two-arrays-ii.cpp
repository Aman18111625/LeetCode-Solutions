class Solution {
public:
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>res;
    //     unordered_map<int,int>mpp;
    //     for(int i=0;i<nums1.size();i++) mpp[nums1[i]]++;
    //     for(int i=0;i<nums2.size();i++)
    //     {
    //         if(mpp[nums2[i]]>0)
    //         {
    //             res.push_back(nums2[i]);
    //             mpp[nums2[i]]--;
    //         }
    //     }
    //     return res;
    // }
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0,n=nums1.size(),m=nums2.size();
        vector<int> res;
        while(i < n && j < m ){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
			        	j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }
        return res;
    }
};