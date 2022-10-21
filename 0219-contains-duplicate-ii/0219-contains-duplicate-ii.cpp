class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
          map[nums[i]].push_back(i);
        }
        for(auto it: map){
          auto vec=it.second;
          if(vec.size()==1) continue;
          for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1]-vec[i]<=k) return true;
          }
        }
        return false;
    }
};