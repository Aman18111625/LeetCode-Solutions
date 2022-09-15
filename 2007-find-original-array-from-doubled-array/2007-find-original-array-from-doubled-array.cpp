class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
      int n=changed.size();
      if(n&1) return {};
      vector<int>ans;
      sort(changed.begin(),changed.end());
      unordered_map<int,int>map;
      for(auto ch: changed) map[ch]++;
      for(int i=0;i<n;i++){
        if(map[changed[i]]==0) continue;
        if(map[changed[i]*2]==0) return {};
        ans.push_back(changed[i]);
        map[changed[i]]--;
        map[changed[i]*2]--;
      }
      return ans;
    }
};
 