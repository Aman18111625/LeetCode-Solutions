class Solution {
public:
    bool isPossible(vector<int>& nums) {
      unordered_map<int,int>map;
      for(auto num : nums) map[num]++;
      for(auto num : nums){
        if(map[num]==0) continue;
        int freq=map[num],curr=num,count=0;
        while(map.count(curr) && map[curr]>=freq){
          freq=max(freq,map[curr]);
          map[curr]--;
          count++;
          curr++;
        }
        if(count<3) return false;
      }
      return true;
    }
};

